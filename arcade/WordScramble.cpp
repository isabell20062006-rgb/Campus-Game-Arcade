#include "WordScramble.h"
#include <cstdlib>
#include <algorithm>

using namespace std;

WordScramble::WordScramble() : livesLeft(5), won(false) {
    wordBank = {"computer", "science", "variable", "function", "pointer", 
                "object", "class", "inheritance", "template", "array"};
    int index = rand() % 10;
    setWord(wordBank[index]);
}

WordScramble::WordScramble(string word, int lives) : livesLeft(lives), won(false) {
    setWord(word);
}

void WordScramble::setWord(string word) {
    originalWord = word;
    scramble();
}

void WordScramble::scramble() {
    scrambledWord = originalWord;
    int n = scrambledWord.length();
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(scrambledWord[i], scrambledWord[j]);
    }
    if (scrambledWord == originalWord && n > 1) {
        scramble();
    }
}

bool WordScramble::tryGuess(string attempt) {
    if (attempt == originalWord) {
        won = true;
        return true;
    }
    livesLeft--;
    return false;
}

void WordScramble::play() {
    string userGuess;
    cout << "--- Welcome to Word Scramble! ---" << endl;
    
    while (livesLeft > 0 && !won) {
        cout << "Scrambled word: " << getScrambled() << endl;
        cout << "Lives left: " << getLivesLeft() << endl;
        cout << "Your guess: ";
        cin >> userGuess;
        
        if (tryGuess(userGuess)) {
            cout << "Correct! You unscrambled the word!" << endl;
        } else {
            cout << "Incorrect guess!" << endl;
        }
    }
    
    if (!won) {
        cout << "Game over! The word was: " << reveal() << endl;
    }
}