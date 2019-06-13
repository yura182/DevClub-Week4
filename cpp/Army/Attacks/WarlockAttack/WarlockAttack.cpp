#include "WarlockAttack.h"

WarlockAttack::WarlockAttack() {
    debugPrint("WarlockAttack created");
}
WarlockAttack::~WarlockAttack() {
    debugPrint("WarlockAttack destroyed");
}

void WarlockAttack::attack(Unit& attacker, Unit& victim) {
    victim.takeDamage(attacker.getDamage());
    
    std::cout << "\033[31m" << attacker.getName();
    std::cout << " " << attacker.getType();
    std::cout << " attacked " << victim.getName() << " " << victim.getType() << "\033[30m" << std::endl;
    
    Warlock &war = dynamic_cast<Warlock&>(attacker);
    
    if ( !war.getDemons().empty() ) {
        std::set<Unit*>::iterator it = war.getDemons().begin();
        
        for ( ; it != war.getDemons().end(); it++ ) {
            if ( victim.isAlive() ) {
                (*it)->attack(victim);
            }
        }
    }
    
    if ( victim.isAlive() ) {
        victim.counterAttack(attacker);
    } else {
        victim.notify();
    }
}
