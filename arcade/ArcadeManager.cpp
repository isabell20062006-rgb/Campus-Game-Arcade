#include "ArcadeManager.h"
#include "SlotMachine.h"
#include "NumberGuesser.h"
#include "WordScramble.h"
#include <iostream>

using namespace std;

ArcadeManager::ArcadeManager() : isRunning(true) {}

void ArcadeManager::startArcade() {
    int choice;
    while (isRunning) {
        cout << endl << "--- ARCADE MENU ---" << endl;
        cout << "1. Play Slot Machine" << endl;
        cout << "2. Play Number Guesser" << endl;
        cout << "3. Play Word Scramble" << endl;
        cout << "4. Exit Arcade" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1: runSlotMachine(); break;
            case 2: runNumberGuesser(); break;
            case 3: runWordScramble(); break;
            case 4: isRunning = false; break;
            default: cout << "Invalid selection!" << endl;
        }
    }
    cout << "Thank you for visiting the Arcade!" << endl;
}

void ArcadeManager::runSlotMachine() {
    SlotMachine sm;
    int betAmount;
    cout << endl << "--- SLOT MACHINE ---" << endl << "Current Credits: " << sm.getCredits() << endl;
    cout << "Enter bet amount: ";
    cin >> betAmount;
    sm.placeBet(betAmount);
    sm.spin();
}

void ArcadeManager::runNumberGuesser() {
    int diff;
    cout << endl << "--- NUMBER GUESSER ---" << endl << "Select Difficulty (1=Easy, 2=Medium, 3=Hard): ";
    cin >> diff;
    NumberGuesser ng(diff);
    ng.play();
}

void ArcadeManager::runWordScramble() {
    WordScramble ws;
    string guess;
    cout << endl << "--- WORD SCRAMBLE ---" << endl << "Unscramble this word: " << ws.getScrambled() << endl;
    cout << "Your guess: ";
    cin >> guess;
    
    if (ws.checkGuess(guess)) {
        cout << "Excellent job! That is correct." << endl;
    } else {
        cout << "Incorrect guess!" << endl;
    }
}