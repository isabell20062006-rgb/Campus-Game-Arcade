#include "ArcadeManager.h"
#include <iostream>

using namespace std;

int ArcadeManager::totalSessions = 0;

ArcadeManager::ArcadeManager() {
    totalSessions++;
    for (int i = 0; i < 10; i++) {
        leaderboard[i].playerName = "EMPTY";
        leaderboard[i].score = 0;
    }
}

void ArcadeManager::launchMenu() {
    int choice;
    do {
        cout << endl << "=== CAMPUS ARCADE ===" << endl;
        cout << "1. Slot Machine" << endl;
        cout << "2. Number Guesser" << endl;
        cout << "3. Word Scramble" << endl;
        cout << "4. View Stats" << endl;
        cout << "5. Quit" << endl;
        cout << "Choice: ";
        cin >> choice;
        switch(choice) {
            case 1: runSlots(); break;
            case 2: runGuesser(); break;
            case 3: runScramble(); break;
            case 4: printStats(); break;
        }
    } while (choice != 5);
}

void ArcadeManager::printLeaderboard() {
    cout << "Leaderboard display system is active." << endl;
}

void ArcadeManager::runSlots() {
    SlotMachine sm;
    int betAmount;
    cout << "Current Coins: " << sm.getCoins() << endl;
    cout << "Enter bet amount: ";
    cin >> betAmount;
    sm.spin(betAmount);
    sm.printResult();
}

void ArcadeManager::runGuesser() {
    NumberGuesser ng;
    ng.play();
}

void ArcadeManager::runScramble() {
    WordScramble ws;
    ws.play();
}

void ArcadeManager::printStats() {
    cout << "Total Arcade Sessions started: " << totalSessions << endl;
    NumberGuesser::printGamesPlayed();
}