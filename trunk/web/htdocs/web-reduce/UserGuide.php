﻿<?php
$page_title = 'Web REDUCE User Guide';
$header_title = 'Web REDUCE User Guide';
include '../include/begin-head.php';
include '../include/begin-body.php';
?>
<h2>Contents</h2>
<ul>
    <li><a href="#MainPage">Main Page</a></li>
    <li><a href="#REDUCEMenu">REDUCE Menu</a></li>
    <li><a href="#FileMenu">File Menu</a></li>
    <li><a href="#ViewMenu">View Menu</a></li>
    <li><a href="#TemplatesMenu">Templates Menu</a></li>
    <li><a href="#FunctionsMenu">Functions Menu</a></li>
    <li><a href="#HelpMenu">Help Menu</a></li>
    <li><a href="#QueryString">Controlling Web REDUCE via the URL Query String</a></li>
</ul>

<h2 id="MainPage">Main Page</h2>

<p>
    Web REDUCE normally starts loading as soon as its main page is
    opened and starts running as soon as it has loaded, which should
    be almost instantaneous except for the first time you run it in a
    particular browser or after an update to the Web REDUCE engine, in
    which case there may be a noticeable pause. Web REDUCE will stop
    when you close its main page; it is not necessary to explicitly
    terminate REDUCE. However, you can stop and start Web REDUCE by
    using the <a href="#REDUCEMenu">REDUCE Menu</a>, and stop Web
    REDUCE by executing the command <code>BYE</code> or <code>QUIT</code>,
    as usual. To fully reset and restart Web REDUCE just reload its
    main page.
</p>
<p>
    The Web REDUCE main page consists of a menu bar and two panes, one
    above the other. The top pane displays all the REDUCE input and
    output in the current session. It is read-only. The bottom pane is
    an input editor that supports all the standard keyboard and
    mouse-based editing facilities normally provided by your platform.
    Both panes display vertical scroll bars when necessary. The top
    pane wraps input when possible and displays a horizontal scroll
    bar when necessary; text wraps in the input editor. The input
    editor can be resized vertically by dragged the bottom right-hand
    corner, and in Chromium-based browsers the I/O display can
    similarly be resized vertically by dragged the bottom right-hand
    corner. Input text can always be copied from the top pane; plain
    text output can also be copied but typeset mathematical output
    cannot currently be copied in such a way that it can be re-input
    into REDUCE.
</p>
<p>
    You type (or paste) REDUCE input into the input editor pane, edit
    it as necessary, and then click on the <em>Send Input</em>
    button, which sends the input to REDUCE and echos it in the top
    pane. This clears the input editor, but you can scroll through
    previous input (entered via the input editor) using the
    <em>Earlier Input</em> and <em>Later Input</em> buttons.
    Scrolling to input later than the last previous input clears the
    input editor pane back to its state before you started scrolling.
</p>
<p>
    When keyboard focus is in the input editor pane, the following
    keyboard shortcuts are active:
</p>
<table class="table">
    <thead>
        <tr>
            <th>Keyboard Shortcut</th>
            <th>Action</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td><em>Control+Enter</em></td>
            <td>Send Input (auto-terminated)</td>
        </tr>
        <tr>
            <td><em>Control+Shift+Enter</em></td>
            <td>Send Input (not auto-terminated)</td>
        </tr>
        <tr>
            <td><em>Control+UpArrow</em></td>
            <td>Earlier Input</td>
        </tr>
        <tr>
            <td><em>Control+DownArrow</em></td>
            <td>Later Input</td>
        </tr>
    </tbody>
</table>
<p>
    where <em>Enter</em> is the <em>Return</em> or <em>Enter</em>
    key and <em>UpArrow</em> / <em>DownArrow</em> are the cursor up /
    down keys, respectively.
</p>
<p>
    Sending input to REDUCE strips any trailing white space and
    normally auto-terminates it by adding a semicolon if there was no
    final terminator. However, holding the <em>Shift</em> key while
    clicking on the <em>Send Input</em> button or pressing
    <em>Control+Enter</em> suppresses auto-termination.
</p>
<p>
    You can edit previous input recalled into the input editor as
    necessary and then send it to REDUCE. Input can be multi-line, in
    which case REDUCE processes all the lines together. The
    <em>Send Input</em> action is disabled until REDUCE is running,
    and the <em>Earlier Input</em> and <em>Later Input</em> actions
    are disabled unless there is earlier or later input, respectively.
</p>
<p>
    Holding down the <em>Alt</em> key during any of the above input gestures
    causes Web REDUCE to treat the keyboard input like file input with
    echo enabled, meaning that the input is echoed by REDUCE so that
    input statements and their output are interleaved. This only affects
    multi-statement input.
</p>

<h2 id="REDUCEMenu">REDUCE Menu</h2>
<p>
    The <em>REDUCE</em> menu provides the following items:
</p>
<dl>
    <dt>Start REDUCE</dt>
    <dd>
        Selecting this item clears the Input/Output Display and then
        starts Web REDUCE, which displays the usual CSL REDUCE start-up
        message. It is disabled if Web REDUCE is already running.
    </dd>
    <dt>Stop REDUCE</dt>
    <dd>
        Selecting this item stops Web REDUCE and displays the message
        "REDUCE stopped". It is disabled if Web REDUCE is not running.
        Executing either of the usual commands <code>BYE</code> or
        <code>QUIT</code> should have exactly the same effect.
    </dd>
    <dt>Clear I/O Display</dt>
    <dd>
        Selecting this item clears the Input/Output Display, but has no
        other effect.
    </dd>
    <dt>Print I/O Display</dt>
    <dd>
        Selecting this item prints the Input/Output Display, but has no
        other effect. It uses the normal printing facilities provided by
        the web browser, and prints the whole of the current contents of
        the Input/Output Display, not just the visible part. The printed
        version should look more-or-less identical to what is shown on the
        screen, including colour and typeset mathematics if enabled. This
        is, of course, subject to a suitable printer setup, but it seems
        to work well on Windows 10 outputting to a PDF file.
    </dd>
</dl>

<h2 id="FileMenu">File Menu</h2>
<p>
    The <em>File</em> menu uses the experimental
    <a href="https://web.dev/file-system-access/">File System Access API</a> provided by
    <a href=https://en.wikipedia.org/wiki/Chromium_(web_browser)>Chromium-based browsers</a>
    such as Chrome, Edge, and Opera on desktop platforms, which works well. On other browsers,
    such as Firefox, Safari and on mobile platforms, much cruder facilities have to be used, which work much less well.
    <strong>If you intend to use file input or output then I recommend that you use a Chromium-based browsers on a
        desktop platform!</strong>
    The <em>File</em> menu is enabled only when Web REDUCE is running, and provides the following items:
</p>
<dl>
    <dt>Echo File Input</dt>
    <dd>
        When this check box is checked, input files are echoed to the
        screen or to the output file if one is active. It is checked
        by default.
    </dd>
    <dt>Input from File&hellip;</dt>
    <dd>
        Selecting this item displays a file picker that allows a file
        to be selected and input into Web REDUCE. This emulates the
        REDUCE <code>IN</code> command, except that Web REDUCE
        currently supports only one input file at a time and files
        need not be terminated with <code>;end;</code> (although this
        should do no harm).
        <strong>Note that currently when input is from a file it is
            never coloured and only typeset mathematical output is
            coloured if I/O Colouring is enabled.</strong>
        Web REDUCE displays an information message that it is now
        inputting from the specified file.
    </dd>
    <dt>Output to File&hellip;</dt>
    <dd>
        Selecting this item displays a dialogue that allows a file
        to be selected and output from Web REDUCE to be sent to it.
        It is disabled when an output file is open. File output disables
        typeset mathematics output temporarily so that the contents of
        the output file should be plain ASCII text. This emulates the
        REDUCE <code>OUT</code> command, except that Web REDUCE
        currently supports only one open output file at a time. Web
        REDUCE displays an information message that it is now
        outputting to the specified file.
    </dd>
    <dd>
        On Chromium-based desktop browsers, the normal file picker is used to select an output file, and if it already
        exists you can choose to overwrite it. On other browsers, a dialogue allows the default output file name to be
        edited, but the file will be output to a location determined by your browser, which you may be able to configure
        as one of your browser's settings. Also, your browser's normal download dialogue will appear when you shut the
        output file, which you must acknowledge appropriately, because saving the output file is unavoidably emulated as
        a download. If the output file already exists then the new file will be automatically renamed and the existing
        file will not be overwritten.
    </dd>
    <dt>Output Here</dt>
    <dd>
        Selecting this item redirects output to the terminal, without
        closing the output file. It is enabled only when output is
        directed to a file. This emulates the REDUCE <code>OUT T</code> command.
        Web REDUCE displays an information message that it is now
        outputting to the terminal.
    </dd>
    <dt>Output to Open File</dt>
    <dd>
        Selecting this item redirects output to the previously
        selected output file. It is enabled only when output is
        redirected from a file back to the terminal. This emulates the
        REDUCE <code>OUT</code> command specifying the previously
        selected output file, except that Web REDUCE currently does
        not require (or allow) you to specify the file, since only one
        output file can be open. Web REDUCE displays an information
        message that it is now outputting to the specified file.
    </dd>
    <dt>Shut Output File</dt>
    <dd>
        Selecting this item closes the current output file and directs
        output back to the terminal. It is enabled only when an output
        file is open. This emulates the REDUCE <code>SHUT</code> command,
        except that Web REDUCE currently does not require (or allow)
        you to specify the file to shut, since only one output file
        can be open. Web REDUCE displays an information message that
        it is now outputting to the terminal.
    </dd>
</dl>

<h2 id="ViewMenu">View Menu</h2>
<p>
    The <em>View</em> menu provides the following items:
</p>
<dl>
    <dt>I/O Colouring</dt>
    <dd>
        When this check box is checked, Web REDUCE displays input coloured
        red and output coloured blue in the Input/Output Display;
        otherwise the default colour (normally black) is used for both
        input and output. It is checked by default.
    </dd>
    <dt>Typeset Maths</dt>
    <dd>
        When this check box is checked, Web REDUCE displays algebraic-mode
        mathematical output more-or-less as it would be typeset.
        It is checked by default. Output
        display will be significantly faster when Typeset Maths is turned
        off. Typeset output should appear very similar to that displayed
        by the CSL REDUCE GUI and <a href="https://www.texmacs.org/">TeXmacs</a>
        since it is generated by the same REDUCE code, although in Web
        REDUCE it is displayed using the
        <a href="https://www.mathjax.org">MathJax</a> JavaScript library.
        Right-clicking on typeset math output pops up the MathJax context
        menu.
    </dd>
    <dt>Centre Typeset Maths</dt>
    <dd>
        When this check box is checked, Web REDUCE displays typeset maths
        centred horizontally; otherwise it is left justified.
        It is checked by default.
    </dd>
</dl>

<h2 id="TemplatesMenu">Templates Menu</h2>

<p>
    The <em>Templates</em> menu facilitates construction of structured
    expressions and statements whose syntax might not be immediately
    obvious, especially to a novice. The template dialogues all
    provide hyperlinks to the key sections of the HTML version of the
    REDUCE Manual, which open in a new tab in your web browser. The
    dialogues all provide two buttons that apply the filled-in
    template: the <em>Edit</em> button inserts the template output
    into the input editor at the current cursor position, replacing
    any selected text; the <em>Evaluate</em> button sends the template
    output directly to REDUCE for evaluation, adding a terminator just
    as the <em>Send Input</em> button does. These buttons also close
    the dialogue. To close a template dialogue explicitly, click on
    the <em>Close</em> button.
</p>
<p>
    If the template represents an operator with a primary operand then
    this defaults to <em>ws</em>, which is convenient for simple
    interactive calculations, but it can be changed to anything. The
    templates provide some minimal input validation: for example, if
    an element must be an explicit number (rather than a variable that
    must evaluate to a number), the template will check this and
    report an error immediately an inappropriate character is entered.
    The template checks that all input has been provided that is
    required for valid REDUCE syntax.
</p>
<p>
    Templates remember their previous input, but clicking on the
    <em>Reset</em> button resets them to their initial state when Web
    REDUCE was first started.
</p>
<p>
    These templates are intended only for creating simple structures,
    but they can form the basis for arbitrarily complex structures if
    they are entered into the input editor for further editing. The
    fields of expression templates display minimal formatting intended
    to hint at how such an expression would normally be typeset.
</p>
<p>
    The <em>Templates</em> menu provides the following items:
</p>
<dl>
    <dt>Derivative&hellip;</dt>
    <dd>
        This template supports (partial) differentiation involving up to
        three independent variables, each to arbitrary order. The orders
        must be explicit positive integers and the total order
        automatically updates to reflect the number of independent
        variables and their orders. If an order is omitted then it
        defaults to 1. At least one independent variable is required but
        others are optional. The dependent variable defaults to
        <em>ws</em> and the first independent variable defaults to
        <em>x</em>, but both can be changed.
    </dd>
    <dt>Integral&hellip;</dt>
    <dd>
        This template supports both indefinite and definite integration: if
        both limits are omitted then the integral is indefinite; if both
        limits are specified then the integral is definite. The integrand
        defaults to <em>ws</em> and the integration variable defaults
        to <em>x</em>, but both can be changed.
    </dd>
    <dd>
        By default, the template provides a single integral, but if you
        enter another integration variable in a box to the right of the
        primary integration variable then an additional integral appears
        wrapping the previous integral, thus supporting double and triple
        integrals. Matching &int; and <em>d</em> symbol pairs have the
        same colour (blue, green or red) to facilitate adding limits to
        the right &int; symbol.
    </dd>
</dl>

<h2 id="FunctionsMenu">Functions Menu</h2>

<p>
    The <em>Functions</em> menu facilitates access to some of the
    mathematical functions provided by REDUCE via dialogue boxes
    similar to those provided by the <em>Templates</em> menu. The
    function dialogues all provide hyperlinks to the key sections of
    the HTML version of the REDUCE Manual, which open in a new tab in
    your web browser. Hover over a function name to pop up a tooltip
    that gives a hint at its definition, which often uses linearlized
    mathematical notation similar to LaTeX (but without any
    backslashes).
</p>
<p>
    The function dialogue boxes provide a grid of function
    templates. Click on the radio button to the left of the
    function you want to use. The templates display the conventional
    notation used for the functions but with editable text fields
    holding the function arguments. The default arguments are
    either <em>ws</em>, where this seems appropriate, or the
    conventional variable names.
</p>
<p>
    The <em>Functions</em> menu provides the following items:
</p>
<dl>
    <dt>Exp, Log, Power, etc&hellip;</dt>
    <dd>
        This provides the exponential function, various logarithms, power
        and roots (surds or radicals), factorial and binomial
        coefficients, and the hypot and atan<sub>2</sub> functions.
    </dd>
    <dt>Gamma &amp; Beta Functions, etc&hellip;</dt>
    <dd>
        This provides the Gamma, Beta, digamma, polygamma, normalized
        incomplete Gamma and Beta, and dilogarithm functions, Pochhammer's
        symbols, binomial coefficients and the Riemann zeta function.
    </dd>
</dl>

<h2 id="HelpMenu">Help Menu</h2>

<p>
    The <em>Help</em> menu provides the following items, which all
    open in a new browser tab:
</p>
<dl>
    <dt>Web REDUCE User Guide</dt>
    <dd>
        This document.
    </dd>
    <dt>REDUCE Manual</dt>
    <dd>
        The HTML version of the REDUCE Manual.
    </dd>
    <dt>About Run-REDUCE</dt>
    <dd>
        Information about Web REDUCE, including its limitations.
    </dd>
</dl>

<h2 id="QueryString">Controlling Web REDUCE via the URL</h2>

<ul>
    <li>
        If the main Web REDUCE page is opened with the query string
        <code>?noautorun</code> appended to the URL, i.e. <code>/web-reduce/?noautorun</code>,
        then Web REDUCE is not automatically run, but the web page is
        otherwise set up normally.
    </li>
    <li>
        If the main Web REDUCE page is opened with the query string
        <code>?debug</code> appended to the URL, i.e. <code>/web-reduce/?debug</code>, then
        input to and output from REDUCE is logged to the web browser's
        JavaScript console (by calling <code>console.log()</code>).
        This facility is intended for developers.
    </li>
</ul>

<address>Francis Wright, October 2021</address>
</div><!-- opened in begin-body.php -->
<?php include '../include/footer.php'; ?>
</body>

</html>