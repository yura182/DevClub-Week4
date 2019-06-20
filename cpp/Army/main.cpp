#include <iostream>
#include "Units/Soldier/Soldier.h"
#include "Units/Rogue/Rogue.h"
#include "Units/Berserker/Berserker.h"
#include "Units/Vampire/Vampire.h"
#include "Units/Werewolf/Werewolf.h"
#include "Units/Wizard/Wizard.h"
#include "Units/SpellCaster.h"
#include "Units/Healer/Healer.h"
#include "Units/Priest/Priest.h"
#include "Units/Warlock/Warlock.h"
#include "Units/Necromancer/Necromancer.h"

void wait() {
    std::cout << "\033[2;37m" << "Press ENTER to continue..." << "\033[0m";
    std::cin.get();
}

void clean() {
    std::cout << "\x1B" << "[2J" << "\x1B" << "[3J" << "\033[1;1H";
}

int main() {
    clean();
    Unit *sol = new Soldier("Vasya", 5, 8);
    Unit *rog = new Rogue("Grisha", 4, 10);
    // Unit *ber = new Berserker("Tolya", 1, 1);
    // Unit *vam = new Vampire("Gena", 1, 10);
    // Unit *wer = new Werewolf("Kolya", 5, 12);
    // SpellCaster *wiz = new Wizard("Georgy", 10, 4);
    // SpellCaster *heal = new Healer("Dima", 22,9);
    // SpellCaster *pri = new Priest("Anatoliy", 12, 5);
    // SpellCaster *war = new Warlock("Zhenya", 12, 10);
    // SpellCaster *nec = new Necromancer("Timur", 24, 7);
    // SpellCaster *nec1 = new Necromancer("Budlo", 2, 2);
    
    
    // std::cout << *ber << std::endl;
    // std::cout << *vam << std::endl;
    // std::cout << *wer << std::endl;
    // std::cout << *wiz << std::endl;
    // std::cout << *heal << std::endl;
    // std::cout << *pri << std::endl;
    // std::cout << *war << std::endl;
    // std::cout << *nec << std::endl;
    // std::cout << *nec1 << std::endl;
    
    
    
    sol->getLocation().printField();
    std::cout << *sol << std::endl;
    std::cout << *rog << std::endl;
    wait();
    clean();
    
    sol->getLocation().printField();
    sol->attack(*rog);
    wait();
    clean();
    
    sol->move('U');
    sol->move('U');
    sol->getLocation().printField();
    std::cout << *sol << std::endl;
    std::cout << *rog << std::endl;
    sol->attack(*rog);
    std::cout << *sol << std::endl;
    std::cout << *rog << std::endl;
    wait();
    clean();
    
    sol->getLocation().printField();
    std::cout << *sol << std::endl;
    std::cout << *rog << std::endl;
    rog->attack(*sol);
    std::cout << *sol << std::endl;
    std::cout << *rog << std::endl;
    wait();
    clean();
    
    
    Unit *vam = new Vampire("Gena", 1, 10);
    sol->getLocation().printField();
    std::cout << *sol << std::endl;
    std::cout << *rog << std::endl;
    std::cout << *vam << std::endl;

    
    
    
    // std::cout << *ber << std::endl;
    // std::cout << *vam << std::endl;
    // std::cout << *wer << std::endl;
    // std::cout << *wiz << std::endl;
    // std::cout << *heal << std::endl;
    // std::cout << *pri << std::endl;
    // std::cout << *war << std::endl;
    // std::cout << *nec << std::endl;
    // std::cout << *nec1 << std::endl;
    
    // war->useAbility();
    // sol->getLocation().printField();
    // war->move('L');
    // sol->getLocation().printField();
    
    delete sol;
    // delete rog;
    // delete ber;
    // delete vam;
    // delete wer;
    // delete wiz;
    // delete heal;
    // delete pri;
    // delete war;
    // delete nec;
    // delete nec1;
    
    return 0;
}
