﻿<?php
$page_title = 'Web REDUCE';
$header_title = 'Web REDUCE';
include '../include/begin-head.php';
?>
<style type="text/css">
    #IODisplayIframe,
    textarea {
        width: 100%
    }

    #IODisplayIframe {
        border: medium black solid;
        height: 25em;
        resize: vertical;
        /* Works in Chrome but not Firefox; see
        https://stackoverflow.com/questions/8117761/how-can-i-make-an-iframe-resizable */
    }

    textarea {
        font-family: var(--bs-font-monospace);
        /* Bootstrap pre default */
    }

    div.labelling {
        font-weight: bold;
        margin-top: 5px;
        margin-bottom: 2px;
    }

    #buttons {
        margin-top: 5px;
        margin-bottom: 10px;
        display: flex;
        justify-content: space-evenly;
    }

    div.modal-body input[type="text"] {
        text-align: center;
        font-style: italic;
    }

    table.function-templates {
        table-layout: fixed;
        width: 90%;
        margin-left: auto;
        margin-right: auto;
        border-collapse: separate;
        border-spacing: 10px;
    }

    table.function-templates td {
        text-align: center;
        padding-top: 5px;
        padding-bottom: 5px;
    }

    table.function-templates td.selected {
        outline: auto blue medium;
    }

    table.function-templates p {
        margin-top: -5px;
        margin-bottom: 5px;
    }

    .fs-big {
        font-size: 150%;
    }

    .fs-normal {
        font-size: medium;
    }
</style>

<?php
include '../include/begin-body.php';
?>

<!-- Menu bar -->
<nav id="Menubar" class="navbar navbar-expand-lg navbar-light bg-light">
    <div class="container-fluid">
        <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarNavDropdown"
            aria-controls="navbarNavDropdown" aria-expanded="false" aria-label="Toggle navigation">
            <span class="navbar-toggler-icon"></span>
        </button>
        <div class="collapse navbar-collapse" id="navbarNavDropdown">
            <ul class="navbar-nav">
                <!-- REDUCE Menu -->
                <li class="nav-item dropdown">
                    <a class="nav-link dropdown-toggle" href="#" id="REDUCEMenuLink" role="button"
                        data-bs-toggle="dropdown" aria-expanded="false">REDUCE</a>
                    <ul class="dropdown-menu" aria-labelledby="REDUCEMenuLink">
                        <li><button id="StartREDUCEMenuItem" class="dropdown-item" type="button">Start REDUCE</button>
                        </li>
                        <li><button id="StopREDUCEMenuItem" class="dropdown-item" type="button">Stop REDUCE</button>
                        </li>
                        <li><button id="ClearDisplayMenuItem" class="dropdown-item" type="button">Clear I/O
                                Display</button></li>
                        <li><button id="PrintDisplayMenuItem" class="dropdown-item" type="button">Print I/O
                                Display</button></li>
                    </ul>
                </li>
                <!-- File Menu -->
                <li class="nav-item dropdown">
                    <a class="nav-link dropdown-toggle" href="#" id="FileMenuLink" role="button"
                        data-bs-toggle="dropdown" aria-expanded="false">File</a>
                    <ul class="dropdown-menu" aria-labelledby="FileMenuLink">
                        <li><button id="InputFilesMenuItem" class="dropdown-item" type="button">Input from
                                Files&hellip;</button></li>
                        <li><button id="OutputFileMenuItem" class="dropdown-item" type="button">Output to
                                File&hellip;</button></li>
                        <li><button id="ShutFileMenuItem" class="dropdown-item" type="button">Shut Output File</button>
                        </li>
                    </ul>
                </li>
                <!-- View Menu -->
                <li class="nav-item dropdown">
                    <a class="nav-link dropdown-toggle" href="#" id="ViewMenuLink" role="button"
                        data-bs-toggle="dropdown" aria-expanded="false">View</a>
                    <ul class="dropdown-menu" aria-labelledby="ViewMenuLink">
                        <li class="dropdown-item">
                            <input id="IOColouringCheckbox" type="checkbox" checked="checked" />
                            <label for="IOColouringCheckbox">I/O Colouring</label>
                        </li>
                        <li class="dropdown-item">
                            <input id="TypesetMathsCheckbox" type="checkbox" checked="checked" disabled="disabled" />
                            <label for="TypesetMathsCheckbox">Typeset Maths</label>
                        </li>
                        <li class="dropdown-item">
                            <input id="CentreTypesetMathsCheckbox" type="checkbox" checked="checked" />
                            <label for="CentreTypesetMathsCheckbox">Centre Typeset Maths</label>
                        </li>
                    </ul>
                </li>
                <!-- Templates Menu -->
                <li class="nav-item dropdown">
                    <a class="nav-link dropdown-toggle" href="#" id="TemplatesMenuLink" role="button"
                        data-bs-toggle="dropdown" aria-expanded="false">Templates</a>
                    <ul class="dropdown-menu" aria-labelledby="TemplatesMenuLink">
                        <li><button class="dropdown-item" data-bs-toggle="modal" data-bs-target="#DerivativeTemplate"
                                type="button">Derivative&hellip;</button></li>
                        <li><button class="dropdown-item" data-bs-toggle="modal" data-bs-target="#IntegralTemplate"
                                type="button">Integral&hellip;</button></li>
                    </ul>
                </li>
                <!-- Functions Menu -->
                <li class="nav-item dropdown">
                    <a class="nav-link dropdown-toggle" href="#" id="FunctionsMenuLink" role="button"
                        data-bs-toggle="dropdown" aria-expanded="false">Functions</a>
                    <ul class="dropdown-menu" aria-labelledby="FunctionsMenuLink">
                        <li><button class="dropdown-item" data-bs-toggle="modal" data-bs-target="#ExpLogFunctions"
                                type="button">Exp, Log, Power, Root, etc&hellip;</button></li>
                        <li><button class="dropdown-item" data-bs-toggle="modal" data-bs-target="#GammaEtcFunctions"
                                type="button">Gamma &amp; Beta Functions, etc&hellip;</button></li>
                    </ul>
                </li>
                <!-- Help Menu -->
                <li class="nav-item dropdown">
                    <a class="nav-link dropdown-toggle" href="#" id="HelpMenuLink" role="button"
                        data-bs-toggle="dropdown" aria-expanded="false">Help</a>
                    <ul class="dropdown-menu" aria-labelledby="HelpMenuLink">
                        <li><a class="dropdown-item" href="about.php" target="_blank" title="Opens in a new tab.">About
                                Web REDUCE</a></li>
                        <li><a class="dropdown-item" href="UserGuide.php" target="_blank"
                                title="Opens in a new tab.">Web REDUCE User Guide</a></li>
                        <li><a class="dropdown-item" href="/manual/manual.html" target="_blank"
                                title="Opens in a new tab.">REDUCE Manual</a></li>
                    </ul>
                </li>
            </ul>
        </div>
    </div>
</nav>

<div class="labelling">
    <label for="IODisplayIframe">Input/Output Display</label>
</div>
<iframe id="IODisplayIframe" srcdoc='<!DOCTYPE html>
<html>
<head>
    <title>Web REDUCE</title>
    <style>
        body {background-color: white;}
        body, pre {font-family: SFMono-Regular,Menlo,Monaco,Consolas,"Liberation Mono","Courier New",monospace;}
        pre {white-space: pre-wrap; margin: 0; font-size: 14px;}
        pre.info {background-color: yellow;}
    </style>
    <script>MathJax = { tex: { macros: { "*": "\\," } } };</script>
    <script async="async" src="https://cdn.jsdelivr.net/npm/mathjax@3/es5/tex-chtml.js"></script>
</head>
<body>REDUCE is loading. Please wait&hellip;</body>
</html>'>
</iframe>

<div class="labelling">
    <label for="InputTextArea">Input Editor</label>
</div>
<textarea id="InputTextArea" rows="3"></textarea>
<div id="buttons">
    <button id="EarlierButton" type="button" disabled="disabled"
        title="Select earlier keyboard input. Keyboard Shortcut: Control+UpArrow.">▲ Earlier Input</button>
    <button id="SendInputButton" type="button"
        title="Send the input above to REDUCE all at once, terminating with a semicolon if necessary. Keyboard Shortcut: Control+Enter. (Also hold Shift to prevent auto-termination.)">Send
        Input</button>
    <button id="SendStatementsButton" type="button" style="display: none;"
        title="Send the input above to REDUCE statement-by-statement, terminating with a semicolon if necessary. (Hold Shift to prevent auto-termination.)">Send
        Statements</button>
    <button id="LaterButton" type="button" disabled="disabled"
        title="Select later keyboard input. Keyboard Shortcut: Control+DownArrow.">▼ Later Input</button>
</div>
<a href="https://www.mathjax.org">
    <img title="Powered by MathJax" src="https://www.mathjax.org/badge/badge.gif" alt="Powered by MathJax"
        style="float: right" />
</a>

</div><!-- opened in begin-body.php -->

<?php include '../include/footer.php'; ?>

<script src="Main.js"></script>
<script src="InputEditor.js"></script>
<script src="FileMenu.js"></script>

<!-- Modal Dialogues -->
<?php
    include './DerivativeTemplate.inc';
    include './IntegralTemplate.inc';
    include './ExpLogFunctions.inc';
    include './GammaEtcFunctions.inc';
?>
</body>

</html>