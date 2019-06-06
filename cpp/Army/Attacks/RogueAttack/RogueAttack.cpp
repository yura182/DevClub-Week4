#include "RogueAttack.h"

RogueAttack::RogueAttack() {
    debugPrint("RogueAttack created");
}
RogueAttack::~RogueAttack() {
    debugPrint("RogueAttack destroyed");
}

void RogueAttack::attack(Unit& attacker, Unit& victim) {
    victim.takeDamage(attacker.getDamage());
    
    std::cout << "\033[31m" << attacker.getName() << " attacked " << victim.getName() << std::endl;
    
    if ( !victim.isAlive() ) {
        victim.notify();
    }
}
