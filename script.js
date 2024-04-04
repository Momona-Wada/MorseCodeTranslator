const DURATION = 200; // millisecond per digit

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

// execute program
window.onload = function() {
    visualizeMorseCode("10111011100010111000");
};
