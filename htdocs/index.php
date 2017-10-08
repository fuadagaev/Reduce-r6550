<!DOCTYPE html>
<html lang="en" xmlns="http://www.w3.org/1999/xhtml">
<!-- Index page for http://reduce-algebra.sourceforge.net/, http://reduce-algebra.com, etc. -->
<head>
	<meta charset="utf-8" />
	<title>REDUCE Computer Algebra System</title>
	<meta name="Description" content="The REDUCE Computer Algebra System" />
	<meta name="Keywords" content="Open Source, Software, Development, Developers, Projects, Downloads, SF.net, SourceForge, BSD License, Science/Research, OS Portable (Source code to work with many OS platforms), Mathematics, Lisp, REDUCE, reduce-algebra, computer algebra system, CAS" />
	<link rel="icon" type="image/png" href="images/icon.png" />
	<link rel="stylesheet" href="StyleSheet.css" />
	<style type="text/css">
		div#main {
			display: flex;
		}

		#main img {
			float: none;
			margin: 0;
			width: 100%;
			border: thin solid;
		}

		aside {
			width: 250px; /* Firefox seems to need this; Edge doesn't! */
			padding-left: 24px;
		}

			aside iframe {
				border: 0;
				padding: 0;
				margin: 1em 0 0 0;
				width: 250px; /* Edge seems to need this; Firefox doesn't! */
				height: 500px;
				border: 1px solid #333333;
				background-color: #f8f8ff;
			}
	</style>
</head>
<body>
	<div id="content">
		<header>REDUCE</header>
		<p>A portable general-purpose computer algebra system</p>
		<div id="middle">
			<nav>
				<script language="php">
					include 'navigation.inc';
				</script>
			</nav>
			<div id="main">
				<section>
					<p>REDUCE is a system for doing scalar, vector and matrix algebra by computer, which also supports arbitrary precision numerical approximation and interfaces to <a href="http://www.gnuplot.info/">gnuplot</a> to provide graphics. It can be used interactively for simple calculations (as illustrated in the screenshot below) but also provides a full programming language, with a syntax similar to other modern programming languages.</p>
					<p>REDUCE (and its complete source code) is <a href="obtaining.php">available free of charge</a> for most common computing systems, in some cases in more than one version (see below) for the same machine. The <a href="documentation.php">manual and other support documents</a> and tutorials are also included in the distributions.</p>
					<a href="images/reduce_screenshot_1.PNG">
						<img src="images/reduce_screenshot_1.PNG" alt="CSL REDUCE on Microsoft Windows"
							title="CSL REDUCE on Microsoft Windows - click to see the full size image" /></a>
					<p>REDUCE has a long and distinguished place in the history of computer algebra systems (see the <a href="bibliography.php">bibliography</a>). Other systems that address some of the same issues but sometimes with rather different emphasis are <a href="http://www.axiom-developer.org/">Axiom</a>, Macsyma (<a href="http://maxima.sourceforge.net/">Maxima</a>), <a href="http://www.maplesoft.com/products/Maple/">Maple</a> and <a href="http://www.wolfram.com/mathematica/">Mathematica</a>.</p>
					<p>REDUCE is implemented in Lisp (as are Axiom and Macsyma), but this is completely hidden from the casual user. REDUCE primarily runs on either <a href="versions.php">Portable Standard Lisp (PSL) or Codemist Standard Lisp (CSL)</a>, both of which are available in the distributions. PSL is long-established and compiles to machine code, whereas CSL is newer and compiles to byte code. Hence, PSL may be faster but CSL may be available on a wider range of platforms.</p>
				</section>
				<aside>
					<h2 style="text-align:center; font-size:medium; margin-bottom:0">SourceForge RSS feeds</h2>
					<iframe src="displayRSSfeed.php?https://sourceforge.net/p/reduce-algebra/news/feed.rss">Please use a browser that supports the HTML iframe element.</iframe>
					<iframe src="displayRSSfeed.php?https://sourceforge.net/p/reduce-algebra/activity/feed?source=project_activity">Please use a browser that supports the HTML iframe element.</iframe>
					<p style="text-align:center; font-size:small">RSS feed display courtesy of <a href="http://simplepie.org/">SimplePie</a></p>
				</aside>
			</div>
			<!--/#main-->
		</div>
		<!--/#middle-->
		<script language="php">
			include 'footer.inc';
		</script>
	</div>
	<!--/#content-->
</body>
</html>
