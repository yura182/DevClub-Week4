#include "Randomizer.h"

int randValue(int value) {
    std::srand(value + time(0));
    
    return value - 10 + std::rand() % 20;
}
