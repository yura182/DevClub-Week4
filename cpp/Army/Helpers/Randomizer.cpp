#include "Randomizer.h"

int randValue(int value) {
    static bool seeded = false;
    
    int part = value / 5;
    
    if ( !seeded ) {
        std::srand(time(0));
        seeded = true;
    }
    
    return value - part / 2 + std::rand() % part;
}
