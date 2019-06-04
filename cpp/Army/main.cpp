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
    Unit *sol = new Soldier("Vasya");
    Unit *rog = new Rogue("Grisha");
    Unit *ber = new Berserker("Tolya");
    Unit *vam = new Vampire("Gena");
    Unit *wer = new Werewolf("Kolya");
    SpellCaster *wiz = new Wizard("Georgy", 50);
    
    
    std::cout << *sol << std::endl;
    std::cout << *rog << std::endl;
    std::cout << *ber << std::endl;
    std::cout << *vam << std::endl;
    std::cout << *wer << std::endl;
    std::cout << *wiz << std::endl;
    
    // sol->attack(*rog);
    // std::cout << "------------------" << std::endl;
    // rog->attack(*sol);
    // std::cout << "------------------" << std::endl;
    // ber->attack(*vam);
    // std::cout << "------------------" << std::endl;
    // sol->attack(*vam);
    // std::cout << "------------------" << std::endl;
    // wer->attack(*vam);
    // std::cout << "------------------" << std::endl;
    // std::cout << *sol << std::endl;
    // wiz->castAction(*sol, wiz->getSpell());
    // std::cout << *ber << std::endl;
    // wiz->castAction(*ber, wiz->getSpell());
    
    // std::cout << *sol << std::endl;
    // std::cout << *rog << std::endl;
    // std::cout << *ber << std::endl;
    // std::cout << *vam << std::endl;
    std::cout << *wer << std::endl;
    std::cout << *wiz << std::endl;
    
    wiz->castAction(*wer, wiz->getSpell("Fireball"));
    std::cout << *wer << std::endl;
    wer->useAbility();
    std::cout << *wer << std::endl;
    wiz->castAction(*wer, wiz->getSpell("Fireball"));
    std::cout << *wer << std::endl;
    wer->useAbility();
    std::cout << *wer << std::endl;
    std::cout << wiz->getSpellBook() << std::endl;
    
    delete sol;
    delete rog;
    delete ber;
    delete vam;
    delete wer;
    delete wiz;
    
    return 0;
}
