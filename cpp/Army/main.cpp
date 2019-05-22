#include <iostream>
// #include "Units/Unit.h"
// #include "States/State.h"
#include "Units/Soldier/Soldier.h"
#include "Units/Rogue/Rogue.h"
#include "Units/Berserker/Berserker.h"

int main() {
    std::cout << "\x1B" << "[2J" << "\x1B" << "[3J" << "\033[1;1H";
    Unit *sol = new Soldier("Vasya", 10, 3);
    Unit *rog = new Rogue("Grisha", 8, 4);
    Unit *ber = new Berserker("Tolya", 10, 2);
    
    std::cout << *sol << std::endl;
    std::cout << *rog << std::endl;
    std::cout << *ber << std::endl;
    
    sol->attack(*rog);
    std::cout << "------------------" << std::endl;
    rog->attack(*sol);
    std::cout << "------------------" << std::endl;
    ber->attack(*rog);
    
    std::cout << *sol << std::endl;
    std::cout << *rog << std::endl;
    std::cout << *ber << std::endl;
    
    delete sol;
    delete rog;
    delete ber;
    
    return 0;
}
