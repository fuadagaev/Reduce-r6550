// Main source code

'use strict';

const debug = (location.search === '?debug');

// Set up access to document elements and reset their defaults for when the page is reloaded:
const startREDUCEMenuItem = document.getElementById("StartREDUCEMenuItem");
const stopREDUCEMenuItem = document.getElementById("StopREDUCEMenuItem");
const clearDisplayMenuItem = document.getElementById("ClearDisplayMenuItem");
const ioColouringCheckbox = document.getElementById('IOColouringCheckbox');
const typesetMathsCheckbox = document.getElementById('TypesetMathsCheckbox');
const centreTypesetMathsCheckbox = document.getElementById('CentreTypesetMathsCheckbox');
const inputDiv = document.getElementById('InputDiv');
inputDiv.innerHTML = "";
inputDiv.focus();
const earlierButton = document.getElementById('EarlierButton');
earlierButton.disabled = true;
const sendInputButton = document.getElementById('SendInputButton');
const laterButton = document.getElementById('LaterButton');
laterButton.disabled = true;
const fileMenuLink = document.getElementById("FileMenuLink");
const templatesMenuLink = document.getElementById("TemplatesMenuLink");
const functionsMenuLink = document.getElementById("FunctionsMenuLink");
let ioDisplayWindow, ioDisplayHead, ioDisplayBody;
let noOutput = true, hideOutput = false;
let worker;

// Global variables accessed in more than one module:
var echo = false;  // setting of REDUCE echo switch, accessed in FileMenu.mjs and InputEditor.mjs
var inputFromKbd, outputToFile, outputToArray; // assigned in FileMenu.mjs and InputEditor.mjs

function setRunningState(running) {
    startREDUCEMenuItem.disabled = running;
    stopREDUCEMenuItem.disabled = !running;
    sendInputButton.disabled = !running;
    typesetMathsCheckbox.disabled = !running;
    fileMenuLink.classList.toggle("disabled", !running);
    templatesMenuLink.classList.toggle("disabled", !running);
    functionsMenuLink.classList.toggle("disabled", !running);
}

setRunningState(false);

if (typeof Worker === "undefined") {
    // This is not a sufficient condition!
    alert("This browser does not support Web Workers and so cannot run Web-REDUCE!");
    throw new Error("Can't run REDUCE!");
}

/**
 * Scroll the REDUCE IO display to the bottom.
 */
function scrollIODisplayToBottom() {
    ioDisplayWindow.scroll(0, ioDisplayBody.scrollHeight);
}

function clearIODisplay() {
    ioDisplayBody.innerHTML = "";
}

function sendPlainTextToIODisplay(text, displayClass) {
    if (noOutput) {
        // This code executes immediately after REDUCE loads:
        window.scrollTo(0, document.getElementById("Menubar").offsetTop);
        clearIODisplay();
        setRunningState(true);
        displayClass = false;
        noOutput = false;
    }
    // For now, append text within a <pre> element:
    const pre = document.createElement("pre");
    if (displayClass) pre.classList.add(displayClass);
    pre.innerText = text;
    ioDisplayBody.appendChild(pre);
    scrollIODisplayToBottom();
}

/**
 * Respond to a message from the REDUCE web worker,
 * normally by displaying a processed version in ioDisplay.
 * @param {*} event
 * @returns null
 */
function reduceWebMessageHandler(event) {
    if (hideOutput) { // hide changes of switches etc.
        hideOutput = false;
        return;
    }
    if (event.data.channel === 'stdout') {
        let output = event.data.line;
        try {
            if (outputToFile) { // assigned in "FileMenu.js"
                // Some line termination is necessary, but this produces more vertical space than it should!
                outputToFile.write(output);
                outputToFile.write("\n");
                return;
            } else if (outputToArray) { // assigned in "FileMenu.js"
                outputToArray.push(output);
                outputToArray.push("\n");
                return;
            }
        } catch (ignore) { }
        // If an empty string is passed (ie asking for a blank line of output)
        // it gets lost in the display, so output a single space character.
        if (output == '') {
            debug && console.log("OUTPUT: Empty line"); // for debugging
            sendPlainTextToIODisplay(' ');
        } else {
            debug && console.log(`OUTPUT: ${output}`); // for debugging

            // The mathematical part of the output delived by REDUCE will have the form:
            // latex:\black$\displaystyle\frac{-2\*\arctan\left(x\right)+\log\left(x-1\right)-\log\left(x+1\right)}{4}$
            // delimited by a pair of control characters, \u0002 before and \u0005 after.
            // The TeX in the middle is extracted and MathJax formats it.

            // Detect the case where the output line contains some TeX:
            let n = output.indexOf('\u0002');
            if (n != -1) {
                // Here I not only strip out the material before the "U+0002" but also the
                // "junk" that reads "latex:\black$\displaystyle" and a final "U+0005".
                // Those are fragments that the REDUCE interface for TeXmacs inserts.
                output = output.substring(n + 1 + 26, output.length - 2);
                output = ioDisplayWindow.MathJax.tex2chtml(output);
                output.classList.add("output");
                ioDisplayBody.appendChild(output);
                // The MathJax documentation doesn't tell the whole story!
                // See https://github.com/mathjax/MathJax/issues/2365:
                ioDisplayWindow.MathJax.startup.document.clear();
                ioDisplayWindow.MathJax.startup.document.updateDocument();
                scrollIODisplayToBottom();
            }
            else {
                // Textual rather than mathematical output from REDUCE gets inserted as is.
                // Highlight errors and warnings in output:
                const match = output.match(/^\*{3}(\*{2})?/);
                if (match) {
                    sendPlainTextToIODisplay(output, match[1] ? "error" : "warning");
                } else {
                    // Do not colour if input from file because this may be echoed input:
                    sendPlainTextToIODisplay(output, inputFromKbd && "output");
                }
            }
        }
    }
}

/**
 * Respond to an error from the REDUCE web worker
 * by displaying an alert.
 * @param {*} event
 * @returns null
 */
function reduceWebErrorHandler(event) { console.error(event.message, event) }

function sendToReduce(str) {
    debug && console.log(` INPUT: ${str}`); // for debugging
    // This function posts a string to REDUCE, which treats it rather as if
    // it had been keyboard input. At the start of a run I use this to send a
    // sequence of commands to REDUCE to adjust its input and output processing
    // to suit the needs I have here.
    const buf = new Uint8Array(str.length + 1);
    // Array of 8-bit unsigned integers, null-terminated, to match a C/C++ string
    // (hence the length + 1). The contents are initialized to 0.
    for (let i = 0; i < str.length; i++)
        buf[i] = str.charCodeAt(i); // Returns a number that is the UTF-16 code unit value at the given index.
    worker.postMessage({
        funcName: 'insert_buffer',
        callbackId: '',
        data: buf
    });
}

function startREDUCE() {
    ioDisplayBody.innerHTML = "REDUCE is loading. Please wait&hellip;";
    worker = new Worker("reduce.web.js");
    worker.onmessage = reduceWebMessageHandler;
    worker.onerror = reduceWebErrorHandler;
    sendToReduce('<< lisp (!*redefmsg := nil); load_package tmprint;' +
        ' on nat, fancy; off int >>$');
}

function stopREDUCE() {
    worker.terminate();
    sendPlainTextToIODisplay("REDUCE stopped");
    setRunningState(false);
    noOutput = true; hideOutput = false;
}

// *****************
// Utility Functions
// *****************

function sendToReduceAndEcho(text) {
    sendPlainTextToIODisplay(text, "input");
    sendToReduce(text);
}

const loadedPackages = new Set(); // should probably be in a closure!

/**
 * Load the specified package once only.
 * @param {any} pkg
 */
function loadPackage(pkg) {
    if (loadedPackages.has(pkg)) return;
    sendToReduceAndEcho(`load_package ${pkg};`);
    // Need to wait for REDUCE to digest this.
    // Should wait for the next prompt, but can't at present, so...
    // ...
    loadedPackages.add(pkg);
}

// ************
// Menu Support
// ************

// REDUCE menu support:
startREDUCEMenuItem.addEventListener("click", startREDUCE);
stopREDUCEMenuItem.addEventListener("click", stopREDUCE);
clearDisplayMenuItem.addEventListener("click", clearIODisplay);
document.getElementById("PrintDisplayMenuItem").addEventListener("click", () => ioDisplayWindow.print());

// View menu support:
let ioColouringStyleElement = document.createElement("style");
ioColouringStyleElement.innerText = "pre.input {color: red;} *.output {color: blue;}";

ioColouringCheckbox.addEventListener("change", event => {
    if (ioColouringCheckbox.checked)
        ioDisplayHead.appendChild(ioColouringStyleElement);
    else
        ioColouringStyleElement.remove();
});

function enableTypesetMaths(enable) {
    hideOutput = true;
    sendToReduce(enable ? 'on fancy;' : 'off fancy;');
}

typesetMathsCheckbox.addEventListener("change", () => {
    enableTypesetMaths(typesetMathsCheckbox.checked);
});

centreTypesetMathsCheckbox.addEventListener("change", event => {
    ioDisplayWindow.MathJax.config.chtml.displayAlign = centreTypesetMathsCheckbox.checked ? 'center' : 'left';
    ioDisplayWindow.MathJax.startup.getComponents(); // See http://docs.mathjax.org/en/latest/web/configuration.html
});

// Template and Function menu support:
let preMenuSelectionProps; // set when drop-down menus are shown

/**
* Save relevant properties of the current Selection object.
*/
function saveSelectionProps() {
    // A Selection object represents the range of text selected by the user or the current position of the caret.
    const selection = getSelection();
    preMenuSelectionProps = {
        anchorNode: selection.anchorNode,
        anchorOffset: selection.anchorOffset,
        focusNode: selection.focusNode,
        focusOffset: selection.focusOffset
    }
}

document.getElementById("TemplatesMenuLink")
    .addEventListener('show.bs.dropdown', saveSelectionProps);
document.getElementById("FunctionsMenuLink")
    .addEventListener('show.bs.dropdown', saveSelectionProps);

/**
 * Insert text in inputDiv at caret or replace a selection if there is one.
 */
function inputDivInsert(text) {
    let selBeg = 0;
    const selProps = preMenuSelectionProps;
    const insertionNode = selProps.anchorNode;
    if (insertionNode === inputDiv) {
        // Whole node rather than content selected:
        inputDiv.textContent = text;
    } else {
        // Content selected:
        if (!(inputDiv.contains(insertionNode) && inputDiv.contains(selProps.focusNode))) {
            alert("Invalid selection");
            return;
        }
        selBeg = selProps.anchorOffset;
        let selEnd = selProps.focusOffset;
        if (selBeg > selEnd) { let tmp = selBeg; selBeg = selEnd; selEnd = tmp; }
        const cont = insertionNode.textContent;
        inputDiv.textContent = cont.substr(0, selBeg) + text + cont.substr(selEnd);
    }
    const index = text.search(/\bws\b/), selection = getSelection();
    if (index >= 0) {
        // Select ws if available within inserted text:
        selection.setBaseAndExtent(inputDiv.firstChild, selBeg + index, inputDiv.firstChild, selBeg + index + 2);
    } else {
        // Otherwise, set caret to end of insertion:
        selection.collapse(inputDiv.firstChild, selBeg + text.length);
    }
}

// ********************************************
// Code that requires the iframe to have loaded
// ********************************************

{
    const iframe = document.getElementById("IODisplayIframe");
    iframe.addEventListener("load", () => {
        // Don't try to access the iframe DOM until the iframe has loaded!
        ioDisplayWindow = iframe.contentWindow;
        ioDisplayHead = iframe.contentDocument.head;
        ioDisplayBody = iframe.contentDocument.body;
        ioDisplayHead.appendChild(ioColouringStyleElement); // IOColouringCheckbox initially checked
        if (location.search !== "?noautorun") startREDUCE();
    });
}