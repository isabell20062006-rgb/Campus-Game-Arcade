#ifndef ARCADEMANAGER_H
#define ARCADEMANAGER_H

class ArcadeManager {
private:
    bool isRunning;
    void runSlotMachine();
    void runNumberGuesser();
    void runWordScramble();

public:
    ArcadeManager();
    void startArcade();
    
    inline bool getStatus() const { return isRunning; }
};

#endif