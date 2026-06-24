#include "NumberGuesser.h"
#include <cstdlib>

using namespace std;

int NumberGuesser::gamesPlayed = 0;

NumberGuesser::NumberGuesser() {
    reset();
}

void NumberGuesser::reset() {
    secretNumber = rand() % 20 + 1;
    guessCount = 0;
    solved = false;
    gamesPlayed++;
}

string NumberGuesser::guess(int n) {
    guessCount++;
    if (n > secretNumber) {
        return "Too High";
    } else if (n < secretNumber) {
        return "Too Low";
    } else {
        solved = true;
        return "Correct!";
    }
}

void NumberGuesser::printGamesPlayed() {
    cout << "Total Number Guesser games started: " << gamesPlayed << endl;
}

void NumberGuesser::play() {
    int userGuess;
    cout << "--- Welcome to the Number Guesser Game! ---" << endl;
    cout << "Guess a number between 1 and 20." << endl;

    while (!solved) {
        cout << "Enter your guess: ";
        cin >> userGuess;
        string result = guess(userGuess);
        cout << result << endl;
    }
    cout << "You solved it in " << guessCount << " guesses!" << endl;
}