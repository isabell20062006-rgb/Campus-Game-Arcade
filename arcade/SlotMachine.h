#ifndef SLOTMACHINE_H
#define SLOTMACHINE_H

#include <vector>
#include <string>

class SlotMachine {
private:
    std::vector<std::string> symbols;
    int credits;
    int bet;

public:
    SlotMachine();
    void placeBet(int amount);
    void spin();
    
    // Inline getters for performance and information hiding
    inline int getCredits() const { return credits; }
    inline int getBet() const { return bet; }
};

#endif