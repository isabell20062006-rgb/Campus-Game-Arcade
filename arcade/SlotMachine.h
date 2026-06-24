#ifndef SLOTMACHINE_H
#define SLOTMACHINE_H

#include <iostream>
#include <string>

using namespace std;

class SlotMachine {
public:
    SlotMachine();
    SlotMachine(int startCoins);
    ~SlotMachine();
    void setCoins(int c);
    bool spin(int bet);
    void printResult() const;
    void resetMachine();

    int getCoins() const { return coins; }
    int getTotalSpins() const { return totalSpins; }

private:
    int coins;
    string reel[3];
    int totalSpins;
    string randomSymbol();
};

#endif