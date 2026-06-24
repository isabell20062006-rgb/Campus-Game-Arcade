#ifndef NUMBERGUESSER_H
#define NUMBERGUESSER_H

class NumberGuesser {
private:
    int secretNumber;
    int maxAttempts;

public:
    NumberGuesser(int difficulty = 1);
    void play();
    
    inline int getMaxAttempts() const { return maxAttempts; }
};

#endif