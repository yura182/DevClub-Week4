#ifndef ATTACK_H
#define ATTACK_H

#include "../Debug.h"
#include "../Units/Unit.h"

class Unit;

class BaseAttack {
    public:
        BaseAttack();
        ~BaseAttack();
        
        void attack(Unit& attacker, Unit& victim);
        void counterAttack(Unit& attacker, Unit& victim);
};

#endif // ATTACK_H
