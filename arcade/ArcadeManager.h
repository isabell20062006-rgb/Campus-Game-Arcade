#ifndef ARCADEMANAGER_H
#define ARCADEMANAGER_H

#include <string>
#include "SlotMachine.h"
#include "NumberGuesser.h"
#include "WordScramble.h"

using namespace std;

class ArcadeManager {
public:
    struct HighScore {
        string playerName;
        int score;
    };

    HighScore leaderboard[10];

    ArcadeManager();
    void launchMenu();
    static void printLeaderboard();

private:
    static int totalSessions;
    void runSlots();
    void runGuesser();
    void runScramble();
    void printStats();
};

#endif