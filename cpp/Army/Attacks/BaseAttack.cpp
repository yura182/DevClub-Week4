#include "BaseAttack.h"

BaseAttack::BaseAttack() {
    debugPrint("BaseAttack created");
}
BaseAttack::~BaseAttack() {
    debugPrint("BaseAttack destroyed");
}

void BaseAttack::attack(Unit& attacker, Unit& victim) {
    victim.takeDamage(attacker.getDamage());
    
    std::cout << "\033[31m" << attacker.getName() << " attacked " << victim.getName() << std::endl;
    
    if ( victim.isAlive() ) {
        victim.counterAttack(attacker);
    }
}

void BaseAttack::counterAttack(Unit& attacker, Unit& victim) {
    victim.takeDamage(attacker.getDamage() / 2);
    
    std::cout << "\033[31m" << attacker.getName() << " counter attacked " << victim.getName() << "\033[30m" << std::endl;
}
