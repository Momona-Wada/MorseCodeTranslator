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

const morseTable = [
    "10111", "111010101", "11101011101", "1110101", "1", "101011101", "111011101",
    "1010101", "101", "1011101110111", "111010111", "101110101", "1110111", "11101",
    "11101110111", "10111011101", "1110111010111", "1011101", "10101", "111",
    "1010111", "101010111", "101110111", "11101010111", "1110101110111", "11101110101",
    "10111011101110111", "101011101110111", "1010101110111", "10101010111", "101010101",
    "11101010101", "1110111010101", "111011101110101", "11101110111011101", "1110111011101110111"
];

const characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

function getMorseCode(c) {
    const index = characters.indexOf(c);
    return index !== -1 ? morseTable[index] : "";
}

function convertToMorseCode(text) {
    let morseResult = "";
    for (let i = 0; i < text.length; i++) {
        const char = text[i].toUpperCase();
        if (char !== " ") {
            const morseChar = getMorseCode(char);
            morseResult += morseChar + "000"; // Adding space between characters
        } else {
            morseResult += "0000000"; // Adding seven zeros for space
        }
    }
    return morseResult;
}

// execute program
document.getElementById('morseForm').onsubmit = function(event) {
    event.preventDefault(); // prevent default action of form
    const text = document.getElementById('textInput').value;

    let morseCode = convertToMorseCode(text);

    visualizeMorseCode(morseCode);
};
