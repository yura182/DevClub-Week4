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
    
    std::cout << "\033[31m" << attacker.getName() << " " << attacker.getType() << " attacked " << victim.getName() << " " << victim.getType() <<  " and stealed " << stealedHp << " health points" << std::endl;
    
    if ( victim.isAlive() ) {
        if ( randValue(100) > 102 ) {
            attacker.useAbility(victim);
        }
        
        victim.counterAttack(attacker);
    } else {
        victim.notify();
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
    
    std::cout << "\033[31m" << attacker.getName() << " " << attacker.getType() << " counter attacked " << victim.getName() << " " << victim.getType() <<  " and stealed " << stealedHp << " health points" << std::endl;
    
    if ( victim.isAlive() ) {
        if ( randValue(100) > 103 ) {
            attacker.useAbility(victim);
        }
    } else {
        victim.notify();
    }
}

