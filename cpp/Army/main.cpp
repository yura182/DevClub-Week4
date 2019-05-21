#include <iostream>
#include "Units/Unit.h"
#include "States/State.h"

int main() {
    std::cout << "\x1B" << "[2J" << "\x1B" << "[3J" << "\033[1;1H";
    Unit *sol = new Unit("Vasya", 10, 3);
    Unit *sol2 = new Unit("Grisha", 8, 4);
    
    std::cout << *sol << std::endl;
    std::cout << *sol2 << std::endl;
    
    sol->attack(*sol2);
    
    std::cout << *sol << std::endl;
    std::cout << *sol2 << std::endl;
    
    delete sol;
    delete sol2;
    
    return 0;
}
