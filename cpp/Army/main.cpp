#include <iostream>
#include "Units/Soldier/Soldier.h"
#include "Units/Rogue/Rogue.h"
#include "Units/Berserker/Berserker.h"
#include "Units/Vampire/Vampire.h"
#include "Units/Werewolf/Werewolf.h"
#include "Units/Wizard/Wizard.h"
#include "Units/SpellCaster.h"

int main() {
    std::cout << "\x1B" << "[2J" << "\x1B" << "[3J" << "\033[1;1H";
    Unit *sol = new Soldier("Vasya", 100, 30);
    Unit *rog = new Rogue("Grisha", 80, 40);
    Unit *ber = new Berserker("Tolya", 100, 20);
    Unit *vam = new Vampire("Gena", 110, 30);
    Unit *wer = new Werewolf("Kolya", 90, 15);
    SpellCaster *wiz = new Wizard("Georgy", 50, 10, 50);
    
    std::cout << *sol << std::endl;
    std::cout << *rog << std::endl;
    std::cout << *ber << std::endl;
    std::cout << *vam << std::endl;
    std::cout << *wer << std::endl;
    std::cout << *wiz << std::endl;
    
    sol->attack(*rog);
    std::cout << "------------------" << std::endl;
    rog->attack(*sol);
    std::cout << "------------------" << std::endl;
    ber->attack(*vam);
    std::cout << "------------------" << std::endl;
    sol->attack(*vam);
    std::cout << "------------------" << std::endl;
    wer->attack(*vam);
    
    std::cout << *sol << std::endl;
    std::cout << *rog << std::endl;
    std::cout << *ber << std::endl;
    std::cout << *vam << std::endl;
    std::cout << *wer << std::endl;
    
    wer->useAbility();
    std::cout << *wer << std::endl;
    wer->useAbility();
    std::cout << *wer << std::endl;
    
    delete sol;
    delete rog;
    delete ber;
    delete vam;
    delete wer;
    delete wiz;
    
    return 0;
}
