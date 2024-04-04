const DURATION = 200; // millisecond per digit
const morseForm = document.getElementById('morseForm');
const textInput = document.getElementById('textInput');

function changeBackground(color) {
    document.body.style.backgroundColor = color;
}

function visualizeMorseCode(morseCode) {
    let i = 0; // initialize index

    function updateBackground() {
        if (i >= morseCode.length) {
            clearInterval(interval); // stop at the end of morse code
            return;
        }

        const symbol = morseCode[i];
        if (symbol === '1') {
            changeBackground('white'); // 1 = white
        } else {
            changeBackground('black'); // 0 = black
        }

        i++;
    }

    const interval = setInterval(updateBackground, DURATION); // update every DURATION
}

morseForm.onsubmit = function(event) {
    event.preventDefault(); // prevent default action of form
    const text = textInput.value;

    // wrap convertToMorseCode function using Emscripten's cwrap function
    const convertToMorseCode = Module.cwrap('convertToMorseCode', 'string', ['string']);

    // convert text to morse code and display result
    const morseCode = convertToMorseCode(text);
    visualizeMorseCode(morseCode);
};
