#ifndef WORDSCRAMBLE_H
#define WORDSCRAMBLE_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class WordScramble {
private:
    vector<string> wordBank;
    string originalWord;
    string scrambledWord;
    int livesLeft;
    bool won;

    void scramble();
    void setWord(string word);

public:
    WordScramble();
    WordScramble(string word, int lives);
    void play();
    bool tryGuess(string attempt);

    string getScrambled() const { return scrambledWord; }
    int getLivesLeft() const { return livesLeft; }
    string reveal() const { return originalWord; }
};

#endif