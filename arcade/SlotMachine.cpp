#include "SlotMachine.h"
#include <cstdlib>

using namespace std;

SlotMachine::SlotMachine() : coins(100), totalSpins(0) {
    reel[0] = "BAR";
    reel[1] = "BAR";
    reel[2] = "BAR";
    cout << "--- Welcome to the Slot Machine Game! ---" << endl;
}

SlotMachine::SlotMachine(int startCoins) : totalSpins(0) {
    reel[0] = "BAR";
    reel[1] = "BAR";
    reel[2] = "BAR";
    if (startCoins > 0) {
        coins = startCoins;
    } else {
        coins = 100;
    }
    cout << "--- Welcome to the Slot Machine Game! ---" << endl;
}

SlotMachine::~SlotMachine() {
    cout << "Thanks for playing! You leave with [" << coins << "] coins." << endl;
}

void SlotMachine::setCoins(int c) {
    if (c >= 0) {
        coins = c;
    }
}

string SlotMachine::randomSymbol() {
    string symbols[] = {"CHERRY", "LEMON", "ORANGE", "BELL", "STAR", "DIAMOND"};
    int index = rand() % 6;
    return symbols[index];
}

bool SlotMachine::spin(int bet) {
    if (bet <= 0 || bet > coins) {
        cout << "Error: Invalid bet amount!" << endl;
        return false;
    }

    reel[0] = randomSymbol();
    reel[1] = randomSymbol();
    reel[2] = randomSymbol();

    totalSpins++;
    bool won = false;

    if (reel[0] == reel[1] && reel[1] == reel[2]) {
        coins += (bet * 10);
        won = true;
    } else if (reel[0] == reel[1] || reel[1] == reel[2] || reel[0] == reel[2]) {
        coins += (bet * 2);
        won = true;
    } else {
        coins -= bet;
    }

    return won;
}

void SlotMachine::printResult() const {
    cout << "[ " << reel[0] << " | " << reel[1] << " | " << reel[2] << " ]" << endl;
}

void SlotMachine::resetMachine() {
    coins = 100;
    totalSpins = 0;
    reel[0] = "BAR";
    reel[1] = "BAR";
    reel[2] = "BAR";
}