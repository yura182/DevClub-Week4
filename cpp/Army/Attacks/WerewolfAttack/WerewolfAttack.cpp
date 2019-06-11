#include "WerewolfAttack.h"

WerewolfAttack::WerewolfAttack() {
    debugPrint("WerewolfAttack created");
}
WerewolfAttack::~WerewolfAttack() {
    debugPrint("WerewolfAttack destroyed");
}

void WerewolfAttack::attack(Unit& attacker, Unit& victim) {
    victim.takeDamage(attacker.getDamage());
    
    std::cout << "\033[31m" << attacker.getName();
    std::cout << " " << attacker.getType();
    std::cout << " attacked " << victim.getName() << " " << victim.getType() << "\033[30m" << std::endl;

    if ( victim.isAlive() ) {
        if ( randValue(100) > 102 ) {
            attacker.useAbility(victim);
        }
        
        victim.counterAttack(attacker);
    } else {
        victim.notify();
    }
}
void WerewolfAttack::counterAttack(Unit& attacker, Unit& victim) {
    victim.takeDamage(attacker.getDamage() / 2);
    
    std::cout << "\033[35m" << attacker.getName();
    std::cout << " " << attacker.getType();
    std::cout << " counter attacked " << victim.getName();
    std::cout << " " << victim.getType();
    std::cout << "\033[30m" << std::endl;
    
    if ( victim.isAlive() ) {
        if ( randValue(100) > 103 ) {
            attacker.useAbility(victim);
        }
    } else {
        victim.notify();
    }
}
