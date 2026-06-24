#ifndef NUMBERGUESSER_H
#define NUMBERGUESSER_H

#include <string>
#include <iostream>

using namespace std;

class NumberGuesser {
private:
    int secretNumber;
    int guessCount;
    bool solved;
    static int gamesPlayed;

public:
    NumberGuesser();
    void play();
    string guess(int n);
    void reset();
    static void printGamesPlayed();

    int getGuessCount() const { return guessCount; }
    bool isSolved() const { return solved; }
};

#endif