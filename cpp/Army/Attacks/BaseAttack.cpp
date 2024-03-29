#include "BaseAttack.h"

BaseAttack::BaseAttack() {
    debugPrint("BaseAttack created");
}
BaseAttack::~BaseAttack() {
    debugPrint("BaseAttack destroyed");
}

void BaseAttack::attack(Unit& attacker, Unit& victim) {
    victim.takeDamage(attacker.getDamage());
    
    std::cout << "\033[31m" << attacker.getName();
    std::cout << " " << attacker.getType();
    std::cout << " attacked " << victim.getName() << " " << victim.getType() << "\033[30m" << std::endl;

    if ( victim.isAlive() ) {
        victim.counterAttack(attacker);
    } else {
        victim.notify();
    }
}

void BaseAttack::counterAttack(Unit& attacker, Unit& victim) {
    victim.takeDamage(attacker.getDamage() / 2);
    
    std::cout << "\033[35m" << attacker.getName();
    std::cout << " " << attacker.getType();
    std::cout << " counter attacked " << victim.getName();
    std::cout << " " << victim.getType();
    std::cout << "\033[30m" << std::endl;
    
    if ( !victim.isAlive() ) {
        victim.notify();
    }
}
