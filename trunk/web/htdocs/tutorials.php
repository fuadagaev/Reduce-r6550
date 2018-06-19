<?php

require_once('../php/Smarty/setup.php');
$smarty = new Smarty_REDUCE();

$smarty->assign('header_title', 'Tutorials');

$smarty->assign('head_extras', <<< END_OF_HEAD_EXTRAS
	<style type="text/css">
	pre {
		margin: 0
	}
	</style>
END_OF_HEAD_EXTRAS
);

$smarty->assign('main_content', <<< END_OF_MAIN_CONTENT
	<h2 id="lessons">The REDUCE interactive lessons</h2>
	<p>To run the lessons, you first need to download them, which you can do in any of the following ways:</p>
	<ul>
	<li>Create a directory on your computer called <code>lessons</code> (although you can call it whatever you want), then download <a href="tutorials/lessons.zip">lessons.zip</a> to your <code>lessons</code> directory and unzip it.</li>
	<li>If you have the <a href="https://en.wikipedia.org/wiki/Apache_Subversion">subversion</a> program installed then select a directory on your computer to contain the <code>lessons</code> directory, open a command prompt window in that directory (if necessary) and execute the shell command
	<pre>svn checkout svn://svn.code.sf.net/p/reduce-algebra/code/trunk/packages/lessons</pre>
You can also download individual lesson files this way.
	</li>
	<li id="read-lesson">To download or read just one of the lessons, go to the <a href="https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/packages/lessons/">lessons directory in the SourceForge code repository</a> and click on the lesson file (e.g. <code>less1.red</code>). To download it, click on the link labelled &quot;Download this file&quot; that appears above the file listing, download the file to your computer, optionally create a directory on your computer called <code>lessons</code> (although you can call it whatever you want) and save the file there.</li>
	</ul>
	<p>The lesson files are intended to be perused in REDUCE (although they are plain text files). They consist of long comments interspersed with REDUCE input that is intended to be executed, and they automatically pause every so often so that you can read the next section. But you may need to scroll back to the beginning of the file or to the last pause to see the beginning of the current section. If you want to read a lesson outside of REDUCE then it is easy to do so in your web browser, as described in the <a href="#read-lesson">last bullet point above</a>.</p>
	<ul>
	<li>One way to run the lessons in CSL REDUCE is to start it normally, click on the <code>File / Read...</code> menu item, find your <code>lessons</code> directory in the file selector and then select a lesson file, such as <code>less1.red</code>.</li>
	<li>One way to run the lessons in PSL REDUCE is to start it normally and then execute a command of the following form (customized as appropriate for your computer):
		<pre>in &quot;path/to/lessons/less1.red&quot;;</pre></li>
	</ul>
	<p>It is advisable to run each lesson in a new REDUCE session, otherwise the lessons may interfere with each other.</p>

	<h2>Elementary mathematics tutorials</h2>
	<p>The following tutorials cover the application of REDUCE to a range of elementary mathematics problems at pre-university and first/second-year undergraduate level.  If you spot any errors or have better solutions then please <a href="https://sourceforge.net/users/fjwright/">let us know</a>.  Other tutorials will follow as they are developed.</p>
	<p>It is assumed that the reader is familiar with the mathematics, which is not explained here. Please refer to the <strong>REDUCE User's Manual</strong> <small>[ <a href="manual/manual.html">HTML</a> | <a href="manual/manual.pdf">PDF</a> ]</small> for details of the REDUCE facilities used, which are also not explained here.  You should be able to copy and paste the REDUCE solutions into REDUCE, but you are recommended to try your own solutions first.</p>
	<h4><a href="tutorials/em-tutorial.php">Pre-university algebra tutorial</a></h4>
	<h3>Undergraduate mathematics</h3>
	<h4><a href="tutorials/calculus-tutorial.php">Calculus tutorial</a></h4>
	<h4><a href="tutorials/veclinalg-tutorial.php">Vectors and linear algebra tutorial</a></h4>
	<h4><a href="tutorials/pure-tutorial.php">Pure mathematics tutorial</a></h4>
END_OF_MAIN_CONTENT
);

$smarty->display('main.tpl');

?>