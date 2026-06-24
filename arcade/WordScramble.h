#ifndef WORDSCRAMBLE_H
#define WORDSCRAMBLE_H

#include <string>
#include <vector>

class WordScramble {
private:
    std::vector<std::string> wordBank;
    std::string currentWord;
    std::string scrambledWord;
    
    std::string scramble(std::string word);

public:
    WordScramble();
    void selectNewWord();
    bool checkGuess(const std::string& guess) const;
    
    inline std::string getScrambled() const { return scrambledWord; }
};

#endif