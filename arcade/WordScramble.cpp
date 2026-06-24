#include "WordScramble.h"
#include <cstdlib>
#include <algorithm>

using namespace std;

WordScramble::WordScramble() {
    wordBank = {"cpp", "programming", "encapsulation", "polymorphism", "compiler"};
    selectNewWord();
}

string WordScramble::scramble(string word) {
    string scrambled = word;
    for (size_t i = 0; i < scrambled.length(); ++i) {
        size_t j = rand() % scrambled.length();
        swap(scrambled[i], scrambled[j]);
    }
    return scrambled;
}

void WordScramble::selectNewWord() {
    int index = rand() % wordBank.size();
    currentWord = wordBank[index];
    scrambledWord = scramble(currentWord);
}

bool WordScramble::checkGuess(const string& guess) const {
    return guess == currentWord;
}