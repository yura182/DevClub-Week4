#include "PriestAttack.h"

PriestAttack::PriestAttack() {
    debugPrint("PriestAttack created");
}
PriestAttack::~PriestAttack() {
    debugPrint("PriestAttack destroyed");
}

void PriestAttack::attack(Unit& attacker, Unit& victim) {
    if ( victim.getStateType() == UnitType::UNDEAD ) {
        victim.takeDamage(attacker.getDamage() * DMG_COEFF);
    } else if ( victim.getStateType() == UnitType::ALIVE ) {
        victim.takeDamage(attacker.getDamage());
    }
    
    std::cout << "\033[31m" << attacker.getName() << " " << attacker.getType() << " attacked " << victim.getName() << " " << victim.getType() << std::endl;
    
    if ( victim.isAlive() ) {
        victim.counterAttack(attacker);
    } else {
        victim.notify();
    }
}

void PriestAttack::counterAttack(Unit& attacker, Unit& victim) {
    if ( victim.getStateType() == UnitType::UNDEAD ) {
        victim.takeDamage(attacker.getDamage());
    } else if ( victim.getStateType() == UnitType::ALIVE ) {
        victim.takeDamage(attacker.getDamage() / 2);
    }
    
    std::cout << "\033[31m" << attacker.getName() << " " << attacker.getType() << " counter attacked " << victim.getName() << " " << victim.getType() << "\033[30m" << std::endl;
    
    if ( !victim.isAlive() ) {
        victim.notify();
    }
}
