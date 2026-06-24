#include "NumberGuesser.h"
#include <iostream>
#include <cstdlib>

using namespace std;

NumberGuesser::NumberGuesser(int difficulty) {
    if (difficulty == 3) {
        maxAttempts = 3;
        secretNumber = rand() % 100 + 1;
    } else if (difficulty == 2) {
        maxAttempts = 5;
        secretNumber = rand() % 50 + 1;
    } else {
        maxAttempts = 7;
        secretNumber = rand() % 20 + 1;
    }
}

void NumberGuesser::play() {
    int guess;
    int attempts = 0;
    bool won = false;

    cout << "Guess the number! (Remaining attempts: " << maxAttempts << ")" << endl;

    while (attempts < maxAttempts) {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess == secretNumber) {
            cout << "Correct! You guessed it in " << attempts << " attempts!" << endl;
            won = true;
            break;
        } else if (guess < secretNumber) {
            cout << "Too low!" << endl;
        } else {
            cout << "Too high!" << endl;
        }
    }

    if (!won) {
        cout << "Game over! The number was " << secretNumber << "." << endl;
    }
}