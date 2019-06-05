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

int main() {
    std::cout << "\x1B" << "[2J" << "\x1B" << "[3J" << "\033[1;1H";
    Unit *sol = new Soldier("Vasya");
    // Unit *rog = new Rogue("Grisha");
    // Unit *ber = new Berserker("Tolya");
    // Unit *vam = new Vampire("Gena");
    // Unit *wer = new Werewolf("Kolya");
    // SpellCaster *wiz = new Wizard("Georgy");
    // SpellCaster *heal = new Healer("Dima");
    // SpellCaster *pri = new Priest("Anatoliy");
    SpellCaster *war = new Warlock("Zhenya");
    
    
    std::cout << *sol << std::endl;
    // std::cout << *rog << std::endl;
    // std::cout << *ber << std::endl;
    // std::cout << *vam << std::endl;
    // std::cout << *wer << std::endl;
    // std::cout << *wiz << std::endl;
    // std::cout << *heal << std::endl;
    // std::cout << *pri << std::endl;
    std::cout << *war << std::endl;
    
    war->showSpellBook();
    war->castAction(war->getSpell("Summon Demon"));
    war->useAbility();
    war->useAbility();
    war->useAbility();
    war->useAbility();
    war->showSpecial();
    war->attack(*sol);
    std::cout << *war << std::endl;
    std::cout << *sol << std::endl;
    war->showSpecial();
    // pri->attack(*sol);
    // pri->attack(*vam);
    // std::cout << *sol << std::endl;
    // std::cout << *vam << std::endl;
    // std::cout << "------------------" << std::endl;
    
    // pri->castAction(*sol, pri->getSpell("Fireball"));
    // pri->castAction(*vam, pri->getSpell("Fireball"));
    
    // std::cout << *sol << std::endl;
    // std::cout << *vam << std::endl;
    
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
    // std::cout << *wer << std::endl;
    // std::cout << *wiz << std::endl;
    
    // wiz->castAction(*wer, wiz->getSpell("Magic Arrow"));
    // std::cout << *wer << std::endl;
    // // wer->useAbility();
    // // std::cout << *wer << std::endl;
    // wiz->castAction(*wer, wiz->getSpell("Fireball"));
    // std::cout << *wer << std::endl;
    // wiz->castAction(*wer, wiz->getSpell("Cure"));
    // std::cout << *wer << std::endl;
    // heal->castAction(*wer, heal->getSpell("Cure"));
    // std::cout << *wer << std::endl;
    // wer->attack(*wer);
    // std::cout << *wer << std::endl;
    // wer->useAbility();
    // std::cout << *wer << std::endl;
    // heal->attack(*sol);
    // std::cout << *heal << std::endl;
    // std::cout << *sol << std::endl;
    
    // std::cout << wiz->getSpellBook() << std::endl;
    
    delete sol;
    // delete rog;
    // delete ber;
    // delete vam;
    // delete wer;
    // delete wiz;
    // delete heal;
    // delete pri;
    delete war;
    
    return 0;
}
