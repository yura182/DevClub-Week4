#ifndef TEXT_HANDLER_H
#define TEXT_HANDLER_H

#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include "templates.cpp"

class TextHandler {
    private:
        const char* filename;
        std::set<char>* characters;
        std::map<char, int>* charactersStatistics;
        std::set<char>* numbers;
        std::map<char, int>* numbersStatistics;
        std::set<char>* specialSymbols;
        std::map<char, int>* specialSymbolsStatistics;
        long long quantity;

        void insert(char symbol, std::set<char>* lst);
        void insert(char symbol, std::map<char, int>* lst);
        bool isLetter(char symbol);
        bool isNumber(char symbol);
        bool isSpecial(char symbol);
    public:
        TextHandler(const char* filename);
        ~TextHandler();

        const std::set<char>& getCharacters() const;
        const std::map<char, int>& getCharactersStatistics() const;
        const std::set<char>& getNumbers() const;
        const std::map<char, int>& getNumbersStatistics() const;
        const std::set<char>& getSpecialSymbols() const;
        const std::map<char, int>& getSpecialSymbolsStatistics() const;
        long long getQuantity() const;

        void parseText();
};

std::ostream& operator<<(std::ostream& out, const TextHandler& handler);

#endif //TEXT_HANDLER_H