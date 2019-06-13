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

int main() {
    std::cout << "\x1B" << "[2J" << "\x1B" << "[3J" << "\033[1;1H";
    // Unit *sol = new Soldier("Vasya");
    // Unit *rog = new Rogue("Grisha");
    // Unit *ber = new Berserker("Tolya");
    // Unit *vam = new Vampire("Gena");
    Unit *wer = new Werewolf("Kolya");
    // SpellCaster *wiz = new Wizard("Georgy");
    // SpellCaster *heal = new Healer("Dima");
    // SpellCaster *pri = new Priest("Anatoliy");
    // SpellCaster *war = new Warlock("Zhenya");
    // SpellCaster *nec = new Necromancer("Timur");
    SpellCaster *nec1 = new Necromancer("Budlo");
    
    
    // std::cout << *sol << std::endl;
    // std::cout << *rog << std::endl;
    // std::cout << *ber << std::endl;
    // std::cout << *vam << std::endl;
    std::cout << *wer << std::endl;
    // std::cout << *wiz << std::endl;
    // std::cout << *heal << std::endl;
    // std::cout << *pri << std::endl;
    // std::cout << *war << std::endl;
    // std::cout << *nec << std::endl;
    std::cout << *nec1 << std::endl;
    
    nec1->attack(*wer);
    nec1->castAction(*wer, nec1->getSpell("Fireball"));
    nec1->castAction(*wer, nec1->getSpell("Fireball"));
    wer->useAbility(*nec1);
    nec1->castAction(*wer, nec1->getSpell("Fireball"));
    nec1->attack(*wer);
    std::cout << *nec1 << std::endl;
    nec1->attack(*wer);
    
    // delete sol;
    // delete rog;
    // delete ber;
    // delete vam;
    delete wer;
    // delete wiz;
    // delete heal;
    // delete pri;
    // delete war;
    // delete nec;
    delete nec1;
    
    return 0;
}
