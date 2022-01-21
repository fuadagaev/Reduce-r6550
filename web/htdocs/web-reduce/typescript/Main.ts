/**
 * Main source code
 * @module Main
 */

export interface FileSystemWritableFileStream extends WritableStream {
    write(data: string): Promise<undefined>;
};

// Global variables assigned in more than one module:
export const Global: {
    // Setting of REDUCE echo switch; assigned and read in FileMenu.js and InputEditor.js:
    echo: boolean,
    // Hide REDUCE output if true; assigned in FileMenu.js and InputEditor.js, assigned and read in Main.js:
    hideOutput: boolean,
    // Control REDUCE input and output; assigned in FileMenu.js and InputEditor.js, read in Main.js:
    inputFromKbd: boolean,
    outputToFile: FileSystemWritableFileStream,
    outputToArray: (string | BlobPart)[]
} = {
    echo: false,
    hideOutput: false,
    inputFromKbd: undefined, outputToFile: undefined, outputToArray: undefined
};

/** True if console logging is enabled. */
export const debug = (location.search === '?debug');

// Set up access to document elements and reset their defaults for when the page is reloaded:
const startREDUCEMenuItem = document.getElementById("StartREDUCEMenuItem") as HTMLButtonElement;
const stopREDUCEMenuItem = document.getElementById("StopREDUCEMenuItem") as HTMLButtonElement;
const clearDisplayMenuItem = document.getElementById("ClearDisplayMenuItem") as HTMLButtonElement;
const ioColouringCheckbox = document.getElementById('IOColouringCheckbox') as HTMLInputElement;

/** Typeset Maths View Menu HTML Element. */
export const typesetMathsCheckbox = document.getElementById('TypesetMathsCheckbox') as HTMLInputElement;
const centreTypesetMathsCheckbox = document.getElementById('CentreTypesetMathsCheckbox') as HTMLInputElement;

/** Input Editor HTML Element. */
export const inputDiv = document.getElementById('InputDiv');
inputDiv.innerHTML = "";
inputDiv.focus();

/** Earlier Button HTML Element. */
export const earlierButton = document.getElementById('EarlierButton') as HTMLButtonElement;
earlierButton.disabled = true;

/** Send Input Button HTML Element. */
export const sendInputButton = document.getElementById('SendInputButton') as HTMLButtonElement;

/** Later Button HTML Element. */
export const laterButton = document.getElementById('LaterButton') as HTMLButtonElement;
laterButton.disabled = true;
const fileMenuLink = document.getElementById("FileMenuLink") as HTMLAnchorElement;
const templatesMenuLink = document.getElementById("TemplatesMenuLink") as HTMLAnchorElement;
const functionsMenuLink = document.getElementById("FunctionsMenuLink") as HTMLAnchorElement;
let ioDisplayWindow, ioDisplayHead, ioDisplayBody;

/** True if REDUCE has not yet produced any output. */
export let noOutput = true;
let worker: Worker;

function setRunningState(running: boolean) {
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
 * Scroll the REDUCE I/O display to the bottom.
 */
function scrollIODisplayToBottom() {
    ioDisplayWindow.scroll(0, ioDisplayBody.scrollHeight);
}

function clearIODisplay() {
    ioDisplayBody.innerHTML = "";
}

/**
 * Send plain (i.e. non maths) text to the I/O display by appending
 * a <pre> element. Then scroll the display to the bottom.
 * @param {string} text - The plain text to display.
 * @param {string} [displayClass] - The HTML class attribute to attach to the <pre> element.
 */
export function sendPlainTextToIODisplay(text: string, displayClass?: string) {
    if (noOutput) {
        // This code executes immediately after REDUCE loads:
        window.scrollTo(0, document.getElementById("Menubar").offsetTop);
        clearIODisplay();
        setRunningState(true);
        displayClass = undefined;
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
function reduceWebMessageHandler(event: { data: { channel: string; line: any; }; }) {
    if (Global.hideOutput) { // hide changes of switches etc.
        Global.hideOutput = false;
        return;
    }
    if (event.data.channel === 'stdout') {
        let output = event.data.line;
        try {
            if (Global.outputToFile) { // assigned in "FileMenu.js"
                // Some line termination is necessary, but this produces more vertical space than it should!
                Global.outputToFile.write(output);
                Global.outputToFile.write("\n");
                return;
            } else if (Global.outputToArray) { // assigned in "FileMenu.js"
                Global.outputToArray.push(output);
                Global.outputToArray.push("\n");
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
                    sendPlainTextToIODisplay(output, Global.inputFromKbd && "output");
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
function reduceWebErrorHandler(event: any) { console.error(event.message, event) }

/**
 * Send a text string to REDUCE as input.
 * @param {string} str - The REDUCE input.
 */
export function sendToReduce(str: string) {
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

export function stopREDUCE() {
    worker.terminate();
    sendPlainTextToIODisplay("REDUCE stopped");
    setRunningState(false);
    noOutput = true; Global.hideOutput = false;
}

// *****************
// Utility Functions
// *****************

const toASCII = {
    Α: "!Alpha", Β: "!Beta", Γ: "!Gamma", Δ: "!Delta", Ε: "!Epsilon", Ζ: "!Zeta", Η: "!Eta", Θ: "!Theta",
    Ι: "!Iota", Κ: "!Kappa", Λ: "!Lambda", Μ: "!Mu", Ν: "!Nu", Ξ: "!Xi", Ο: "!Omicron", Π: "!Pi",
    Ρ: "!Rho", Σ: "!Sigma", Τ: "!Tau", Υ: "!Upsilon", Φ: "!Phi", Χ: "!Chi", Ψ: "!Psi", Ω: "!Omega",
    α: "alpha", β: "beta", γ: "gamma", δ: "delta", ε: "epsilon", ζ: "zeta", η: "eta", θ: "theta",
    ι: "iota", κ: "kappa", λ: "lambda", μ: "mu", ν: "nu", ξ: "xi", ο: "omicron", π: "pi",
    ρ: "rho", σ: "sigma", τ: "tau", υ: "upsilon", φ: "phi", χ: "chi", ψ: "psi", ω: "omega",
    "²": "2"
};

/**
 * Map non-ASCII characters in a text string to ASCII.
 * @param {string} text - Input text to be sent to REDUCE.
 * @returns string
 */
function asciify(text: string) {
    let result = "";
    for (const char of text)
        if (char > "\x7F") {
            const newChar = toASCII[char];
            result += newChar ? newChar : char;
        } else
            result += char;
    return result;
}

/**
 * Echo text to the I/O display as REDUCE input and send it to REDUCE,
 * mapping any non-ASCII characters to ASCII.
 * Called in this file, InputEditor.mjs and TempFuncs.mjs.
 * @param {string} text - Input text to be sent to REDUCE.
 */
export function sendToReduceAndEcho(text: string) {
    text = asciify(text);
    sendToReduceAndEchoNoAsciify(text);
}

/**
 * Echo text to the I/O display as REDUCE input and send it to REDUCE,
 * WITHOUT mapping any non-ASCII characters to ASCII.
 * Called in this file, InputEditor.mjs and TempFuncs.mjs.
 * @param {string} text - Input text to be sent to REDUCE.
 */
function sendToReduceAndEchoNoAsciify(text: string) {
    sendPlainTextToIODisplay(text, "input");
    sendToReduce(text);
}

const loadedPackages = new Set(); // should probably be in a closure!

/**
 * Load the specified package once only.
 * @param {string} pkg - Name of package to be loaded.
 */
export function loadPackage(pkg: string) {
    if (loadedPackages.has(pkg)) return;
    sendToReduceAndEchoNoAsciify(`load_package ${pkg};`);
    // Need to wait for REDUCE to digest this.
    // Should wait for the next prompt, but can't at present,
    // so only use when there is a natural pause!
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

/**
 * Enable/disable typeset maths display by turning the fancy switch on/off privately.
 * @param {boolean} enable - True/false to enable/disable.
 */
export function enableTypesetMaths(enable: boolean) {
    Global.hideOutput = true;
    sendToReduce(enable ? 'on fancy;' : 'off fancy;');
}

typesetMathsCheckbox.addEventListener("change", () => {
    enableTypesetMaths(typesetMathsCheckbox.checked);
});

centreTypesetMathsCheckbox.addEventListener("change", event => {
    ioDisplayWindow.MathJax.config.chtml.displayAlign = centreTypesetMathsCheckbox.checked ? 'center' : 'left';
    ioDisplayWindow.MathJax.startup.getComponents(); // See http://docs.mathjax.org/en/latest/web/configuration.html
});

// ********************************************
// Code that requires the iframe to have loaded
// ********************************************

{
    const iframe = document.getElementById("IODisplayIframe") as HTMLIFrameElement;
    iframe.addEventListener("load", () => {
        // Don't try to access the iframe DOM until the iframe has loaded!
        debug && console.log("IODisplayIframe loaded.");
        ioDisplayWindow = iframe.contentWindow;
        ioDisplayHead = iframe.contentDocument.head;
        ioDisplayBody = iframe.contentDocument.body;
        ioDisplayHead.appendChild(ioColouringStyleElement); // IOColouringCheckbox initially checked
        if (location.search !== "?noautorun") startREDUCE();
    });
}