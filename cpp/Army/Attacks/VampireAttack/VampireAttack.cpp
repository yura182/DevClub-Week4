#include "VampireAttack.h"

VampireAttack::VampireAttack() {
    debugPrint("VampireAttack created");
}

VampireAttack::~VampireAttack() {
    debugPrint("VamprireAttack destroyed");
}

void VampireAttack::attack(Unit& attacker, Unit& victim) {
    int victimLoss = victim.getState().getHitPoints();
    int stealedHp = 0;
    
    victim.takeDamage(attacker.getDamage());
    
    victimLoss -= victim.getState().getHitPoints();
    stealedHp = (double) victimLoss * PART_OF_HP;
    
    if ( stealedHp > 0 ) {
        attacker.addHitPoints(stealedHp);
    }
    
    std::cout << "\033[31m" << attacker.getName() << " attacked " << victim.getName() <<  " and stealed " << stealedHp << " health points" << std::endl;
    
    if ( victim.isAlive() ) {
        victim.counterAttack(attacker);
    }
}
void VampireAttack::counterAttack(Unit& attacker, Unit& victim) {
    int victimLoss = victim.getState().getHitPoints();
    int stealedHp = 0;
    
    victim.takeDamage(attacker.getDamage() / 2);
    
    victimLoss -= victim.getState().getHitPoints();
    stealedHp = (double) victimLoss * PART_OF_HP;
    
    if ( stealedHp > 0 ) {
        attacker.addHitPoints(stealedHp);
    }
    
    std::cout << "\033[31m" << attacker.getName() << " counter attacked " << victim.getName() <<  " and stealed " << stealedHp << " health points" << std::endl;
}

