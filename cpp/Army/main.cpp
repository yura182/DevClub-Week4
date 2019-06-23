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
    std::cout << "\033[2;37m" << "\n" << "Press ENTER to continue..." << "\033[0m";
    std::cin.get();
}

void clean() {
    std::cout << "\033[2J" << "\033[3J" << "\033[1;1H";
}

int main() {
    clean();
    
    Unit *sol = new Soldier("Vasya", 5, 8);
    Unit *rog = new Rogue("Grisha", 4, 10);
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
    sol->getLocation().printField();
    wait();
    clean();
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
    wait();
    clean();
    
    rog->move('L');
    sol->getLocation().printField();
    std::cout << *sol << std::endl;
    std::cout << *rog << std::endl;
    std::cout << *vam << std::endl;
    wait();
    clean();
    rog->move('L');
    sol->getLocation().printField();
    std::cout << *sol << std::endl;
    std::cout << *rog << std::endl;
    std::cout << *vam << std::endl;
    rog->attack(*vam);
    vam->attack(*rog);
    std::cout << *sol << std::endl;
    std::cout << *rog << std::endl;
    std::cout << *vam << std::endl;
    wait();
    clean();
    
    sol->getLocation().printField();
    std::cout << *sol << std::endl;
    std::cout << *rog << std::endl;
    std::cout << *vam << std::endl;
    vam->useAbility(*sol);
    vam->useAbility(*rog);
    wait();
    clean();
    
    sol->getLocation().printField();
    std::cout << *sol << std::endl;
    std::cout << *rog << std::endl;
    std::cout << *vam << std::endl;
    wait();
    clean();
    
    rog->move('R');
    sol->getLocation().printField();
    wait();
    clean();
    rog->move('R');
    sol->getLocation().printField();
    rog->useAbility(*sol);
    wait();
    clean();
    sol->getLocation().printField();
    std::cout << *sol << std::endl;
    std::cout << *rog << std::endl;
    std::cout << *vam << std::endl;
    delete(sol);
    delete(vam);
    delete(rog);
    wait();
    clean();
    
    SpellCaster *wiz = new Wizard("Georgy", 10, 4);
    Unit *ber = new Berserker("Tolya", 8, 6);
    wiz->getLocation().printField();
    std::cout << *ber << std::endl;
    std::cout << *wiz << std::endl;
    wait();
    clean();
    
    wiz->move('U');
    wiz->getLocation().printField();
    wait();
    clean();
    
    wiz->move('U');
    wiz->getLocation().printField();
    wiz->castAction(*ber, wiz->getSpell("Fireball"));
    wait();
    clean();
    
    Unit *wer = new Werewolf("Kolya", 5, 6);
    wiz->getLocation().printField();
    std::cout << *ber << std::endl;
    std::cout << *wiz << std::endl;
    std::cout << *wer << std::endl;
    wait();
    clean();
    
    wiz->move('U');
    wiz->getLocation().printField();
    wait();
    clean();
    
    wiz->move('L');
    wiz->getLocation().printField();
    wait();
    clean();
    
    wiz->move('L');
    wiz->getLocation().printField();
    wait();
    clean();
    
    wiz->move('L');
    wiz->getLocation().printField();
    wait();
    clean();
    
    wiz->move('L');
    wiz->getLocation().printField();
    wait();
    clean();
    
    wiz->getLocation().printField();
    std::cout << *ber << std::endl;
    std::cout << *wiz << std::endl;
    std::cout << *wer << std::endl;
    wiz->castAction(*wer, wiz->getSpell("Fireball"));
    std::cout << *ber << std::endl;
    std::cout << *wiz << std::endl;
    std::cout << *wer << std::endl;
    wer->useAbility();
    std::cout << *wer << std::endl;
    wer->useAbility();
    std::cout << *wer << std::endl;
    wait();
    clean();
    
    wer->move('U');
    wiz->getLocation().printField();
    std::cout << *wiz << std::endl;
    wer->useAbility(*wiz);
    std::cout << *wiz << std::endl;
    wait();
    clean();
    
    SpellCaster *heal = new Healer("Dima", 8, 4);
    SpellCaster *pri = new Priest("Anatoliy", 12, 5);
    wiz->getLocation().printField();
    std::cout << *wiz << std::endl;
    std::cout << *wer << std::endl;
    std::cout << *ber << std::endl;
    std::cout << *heal << std::endl;
    std::cout << *pri << std::endl;
    wait();
    clean();
    
    heal->move('U');
    wiz->getLocation().printField();
    wait();
    clean();
    
    heal->move('L');
    wiz->getLocation().printField();
    wait();
    clean();
    
    heal->move('L');
    wiz->getLocation().printField();
    wait();
    clean();
    
    heal->move('U');
    wiz->getLocation().printField();
    heal->showSpellBook();
    std::cout << *wer << std::endl;
    heal->castAction(*wer, heal->getSpell("Cure"));
    std::cout << *wer << std::endl;
    wait();
    clean();
    
    SpellCaster *nec = new Necromancer("Timur", 12, 7);
    wiz->getLocation().printField();
    std::cout << *nec << std::endl;
    wait();
    clean();
    
    pri->move('U');
    wiz->getLocation().printField();
    wait();
    clean();
    
    pri->move('U');
    wiz->getLocation().printField();
    std::cout << *pri << std::endl;
    std::cout << *nec << std::endl;
    pri->attack(*nec);
    std::cout << *pri << std::endl;
    std::cout << *nec << std::endl;
    wait();
    clean();
    
    pri->move('L');
    wiz->getLocation().printField();
    wait();
    clean();
    
    pri->move('L');
    wiz->getLocation().printField();
    wait();
    clean();
    
    pri->move('L');
    wiz->getLocation().printField();
    std::cout << *pri << std::endl;
    std::cout << *ber << std::endl;
    std::cout << *nec << std::endl;
    ber->attack(*pri);
    std::cout << *pri << std::endl;
    std::cout << *ber << std::endl;
    std::cout << *nec << std::endl;
    ber->attack(*pri);
    std::cout << *pri << std::endl;
    std::cout << *ber << std::endl;
    std::cout << *nec << std::endl;
    wait();
    clean();
    
    if ( !pri->isAlive() ) {
        delete pri;
        pri = NULL;
    }
    
    wiz->getLocation().printField();
    wait();
    clean();
    
    SpellCaster *war = new Warlock("Zhenya", 12, 10);
    wiz->getLocation().printField();
    std::cout << *war << std::endl;
    war->useAbility();
    wait();
    clean();
    
    wiz->getLocation().printField();
    war->useAbility();
    wait();
    clean();
    wiz->getLocation().printField();
    war->useAbility();
    wait();
    clean();
    
    wiz->getLocation().printField();
    war->showSpecial();
    
    delete ber;
    delete wer;
    delete wiz;
    delete heal;
    
    if ( pri ) {
       delete pri;
    }
    delete war;
    delete nec;
    
    return 0;
}
