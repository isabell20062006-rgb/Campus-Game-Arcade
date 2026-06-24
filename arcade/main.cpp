#include "ArcadeManager.h"
#include <ctime>
#include <cstdlib>

int main() {
    srand(static_cast<unsigned int>(time(0)));
    ArcadeManager manager;
    manager.startArcade();
    return 0;
}