"""
Pandas-based data analytics for Reduce benchmarks
"""

___author___ = 'Thomas Sturm'
___contact___ = 'https://science.thomas-sturm.de/'
___copyright__ = 'Copyright 2021, Thomas Sturm, Germany'
___license__ = 'CC BY-NC-ND'
___version___ = '$Rev$'

import os
import sys
import pandas as pd
import pathlib
import webbrowser

import html

class Benchmark(pd.DataFrame):
    def __getitem__(self, *arguments, **keywords):
        """
        Overload in order to cast to Benchmark in case a new DataFrame
        is created.
        """
        item = super().__getitem__(*arguments, **keywords)
        if type(item) == pd.DataFrame:
            item = Benchmark(item)
        return item

    def add_means(self):
        def _valid_mean(self, key0):
            a = self[(key0, 'valid_csl')]
            b = self[(key0, 'valid_psl')]
            if a is True and b is True:
                return pd.Series([True], index=['valid_mean'])
            elif a is False or b is False:
                return pd.Series([False], index=['valid_mean'])
            else:
                return pd.Series([None], index=['valid_mean'])
        for key0 in self.columns.levels[0]:
            self[(key0, 'cpu_mean')] = self[[(key0, 'cpu_csl'), (key0, 'cpu_psl')]].mean(axis=1)
            self[(key0, 'gc_mean')] = self[[(key0, 'gc_csl'), (key0, 'gc_psl')]].mean(axis=1)
            self[(key0, 'valid_mean')] = self.apply(_valid_mean, args=(key0,), axis=1)
        return self

    def select(self, selectors):
        """
        Select columns by substring match in any level.
        """
        if type(selectors) == str:
            selectors = [selectors]
        selection = []
        for column in self.columns:
            for selector in selectors:
                if selector in column[0] or selector in column[1]:
                    selection.append(column)
                    break
        return self[selection]

    def speed(self, *, min: float = None, max: float = None):
        """
        Select rows where for all CPU mean times t: min <= t < max.
        """
        if min is None and max is None:
            return self
        level0 = self.columns.levels[0]
        query = True
        for index0 in level0:
            t = self[(index0, 'cpu_mean')]
            if min is not None:
                query = query & (min <= t)
            if max is not None:
                query = query & (t < max)
        return self[query]

    def fast(self, seconds: float = 0.5):
        """
        Select rows where all CPU mean times are less than seconds. Note
        that fast() and slow() complement each other.
        """
        return self.speed(max=seconds)

    def slow(self, seconds: float = 0.5):
        """
        Select rows where at least one CPU mean time is greater than or
        equal to seconds. Note that fast() and slow() complement each
        other.
        """
        return self.speed(min=seconds)

    def plot_scatter(self, *arguments, **keywords):
        if 'alpha' not in keywords:
            keywords['alpha'] = 0.25
        if 'figsize' not in keywords:
            keywords['figsize'] = (6,6)
        if 'grid' not in keywords:
            keywords['grid'] = True
        if 'loglog' not in keywords:
            keywords['loglog'] = True
        p = self.plot.scatter(*arguments, **keywords, zorder=1)
        low_x, high_x = p.get_xlim()
        low_y, high_y = p.get_ylim()
        low = max(low_x, low_y)
        high = min(high_x, high_y)
        return p.plot([low, high], [low, high], c='k', zorder=0, linewidth=0.1)

    def plot_scatter_csl_psl(self, **keywords):
        csl_rows = self.xs('cpu_csl', level=1, axis=1)
        csl_rows = csl_rows.assign(csl=True)
        psl_rows = self.xs('cpu_psl', level=1, axis=1)
        psl_rows = psl_rows.assign(csl=False)
        all_rows = pd.concat([csl_rows, psl_rows], ignore_index=True)
        b = Benchmark(all_rows)
        if 'colorbar' not in keywords:
            keywords['colorbar'] = False
        p = b.plot_scatter(c='csl', colormap='bwr', sharex=False, include_bool=True, **keywords)
        return p

def read_filetree(root: str, key0: str = None):
    class Row(dict):
        def read(self, root: str):
            for stem in 'cpu', 'end', 'gc', 'heapsize', 'start', 'valid':
                for lisp in 'csl', 'psl':
                    key = '_'.join([stem, lisp])
                    key_file_name = os.path.join(root, self['name'], stem + '_' + lisp + '.txt')
                    if os.path.exists(key_file_name):
                        with open(key_file_name) as file:
                            entry = file.read().rstrip()
                            if stem in ('cpu', 'gc'):
                                entry = float(entry) / 1000
                            elif stem in ('heapsize'):
                                entry = int(entry)
                            elif stem in ('start', 'end'):
                                entry = pd.to_datetime(entry)
                            elif stem == 'valid':
                                if entry == "True":
                                    entry = True
                                elif entry == "False":
                                    entry = False
                                else:
                                    entry = None
                    else:
                        entry = None
                    self.update({key: entry})
            return self

    global_attributes = ['uname', 'revision', 'start', 'end', 'parse_args']
    attrs = {}
    for attribute in global_attributes:
        filename = os.path.join(root, 'GLOBAL', attribute + '.txt')
        try:
            with open(filename) as file:
                entry = file.read().rstrip()
                if attribute in ['start', 'end']:
                    entry = pd.to_datetime(entry)
        except FileNotFoundError:
            entry = None
        attrs[attribute] = entry
    rows = []
    for path, directories, files in os.walk(root):
        for file in files:
            if '.red' not in file:
                continue
            row = Row()
            name = os.path.relpath(path, root)
            row.update({"name": name})
            row.read(root)
            rows.append(row)
    columns = []
    for postfix in '_csl', '_psl':
        for stem in 'start', 'cpu', 'gc', 'heapsize', 'valid', 'end':
            columns.append(stem + postfix)
    df = Benchmark(rows, columns=['name'] + columns)
    df.set_index('name', inplace=True)
    df.rename_axis(None, inplace=True)
    df.sort_index(inplace=True)
    df.columns = pd.MultiIndex.from_tuples([(key0 or attrs['revision'], c) for c in df.columns])
    df.attrs = attrs
    return df

def combine2(a: Benchmark, b: Benchmark, *, keys: list = None):
    return Benchmark(pd.concat([a, b], axis=1))

def summary(now: str, ref: str = None, display: bool = False, dump: bool = False,
            full_html: bool = False):
    if ref is None:
        with open(os.path.join(now, 'GLOBAL', 'source.txt')) as file:
            ref = file.read()
    summary_html = os.path.abspath(os.path.join(now, 'summary.html'))
    with open(summary_html, mode='w') as summary:
        if full_html:
            summary.write(html.begin)
        global_attributes = ['uname', 'revision', 'start', 'end']
        ref = read_filetree(ref, 'ref').add_means()
        ref_attrs = pd.DataFrame(ref.attrs.values(), index=ref.attrs.keys(), columns=['ref'])
        now = read_filetree(now, 'now').add_means()
        now_attrs = pd.DataFrame(now.attrs.values(), index=now.attrs.keys(), columns=['now'])
        combo = combine2(ref, now).select(['cpu', 'valid_mean'])
        combo_attrs = combine2(ref_attrs, now_attrs).reindex(global_attributes)
        combo_bad = combo[(combo[('now', 'valid_mean')] == False)]
        combo0 = combo.speed(max=1)
        combo1 = combo.speed(min=1, max=60)
        combo60 = combo.speed(min=60)
        summary.write(html.h3('Global Information'))
        summary.write(html.p(combo_attrs.to_html()))
        if not combo_bad.empty:
            summary.write(html.h3('Possible Problems'))
            summary.write(html.p('Benchmark problems with existing "now" logs that were tested '
                                  'different from existing "ref" logs:'))
            summary.write(html.p(combo_bad.to_html(show_dimensions=True)))
        summary.write(html.h3('Scatter Plots'))
        summary.write(html.p('"Average CPU time" refers to the arithmetic mean between the CSL '
                             'and PSL CPU time of a single benchmark problem. Red and blue dots '
                             'correspond to CSL and PSL, respectively. The scales are '
                             'logarithmic. All times are in seconds.'))
        summary.write('<div style="text-align:center">')
        summary.write(html.plot_scatter(combo, title='All benchmark problems'))
        if not combo0.empty:
            summary.write(html.plot_scatter(combo0, xlim=(0.01, 1), ylim=(0.01, 1),
                title='Average CPU times between 0.01 s and 1 s'))
        if not combo1.empty:
            summary.write(html.plot_scatter(combo1, xlim=(1, 60), ylim=(1, 60),
                                            title='Average CPU time between 1 s and 1 min'))
        if not combo60.empty:
            summary.write(html.plot_scatter(combo60, title='Average CPU times more than 1 min'))
        summary.write('</div>')
        summary.write(html.h3('Detailed CPU Times'))
        if not combo0.empty:
            summary.write(html.h4('Less than one second'))
            summary.write(html.p('Benchmark problems with an average of CSL and PSL CPU times between '
                                 '10 milliseconds and 1 second. All times are in seconds.'))
            summary.write(html.p(combo0.to_html(show_dimensions=True)))
        if not combo1.empty:
            summary.write(html.h4('One second to one minute'))
            summary.write(html.p('Benchmark problems with an average of CSL and PSL CPU time between '
                                 '1 second and 1 minute. All times are in seconds.'))
            summary.write(html.p(combo1.to_html(show_dimensions=True)))
        if not combo60.empty:
            summary.write(html.h3('More than one minute'))
            summary.write(html.p('Benchmark problems with an average of CSL and PSL CPU time of more '
                                 'than 1 minute. All times are in seconds.'))
            summary.write(html.p(combo60.to_html(show_dimensions=True)))
        if full_html:
            summary.write(html.end)
    if dump:
        with open(summary_html, mode = 'r') as summary:
            print(summary.read())
    if display:
        webbrowser.open(pathlib.Path(summary_html).as_uri(), new=1)
