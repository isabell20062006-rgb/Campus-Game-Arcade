#include "SlotMachine.h"
#include <iostream>
#include <cstdlib>

using namespace std;

SlotMachine::SlotMachine() : credits(100), bet(0) {
    symbols = {"CHERRY", "LEMON", "ORANGE", "BELL", "STAR", "DIAMOND"};
}

void SlotMachine::placeBet(int amount) {
    if (amount > 0 && amount <= credits) {
        bet = amount;
        credits -= amount;
    } else {
        cout << "Invalid bet amount!" << endl;
    }
}

void SlotMachine::spin() {
    if (bet == 0) {
        cout << "Please place a bet first." << endl;
        return;
    }

    int s1 = rand() % symbols.size();
    int s2 = rand() % symbols.size();
    int s3 = rand() % symbols.size();

    cout << "[ " << symbols[s1] << " | " << symbols[s2] << " | " << symbols[s3] << " ]" << endl;

    if (s1 == s2 && s2 == s3) {
        int winnings = bet * 10;
        credits += winnings;
        cout << "JACKPOT! You won " << winnings << " credits!" << endl;
    } else if (s1 == s2 || s2 == s3 || s1 == s3) {
        int winnings = bet * 2;
        credits += winnings;
        cout << "Match 2! You won " << winnings << " credits." << endl;
    } else {
        cout << "No match. Better luck next time!" << endl;
    }
    bet = 0; 
}