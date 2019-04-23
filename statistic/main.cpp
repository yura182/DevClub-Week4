#include <iostream>
#include "TextHandler.h"

int main() {
    TextHandler* handler = new TextHandler("symbols.txt");

    handler->parseText();

    std::cout << *handler << std::endl;

    return 0;
}