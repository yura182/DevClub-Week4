#ifndef ATTACK_H
#define ATTACK_H

#include "../Debug/Debug.h"
#include "../Units/Unit.h"

class Unit;

class BaseAttack {
    public:
        BaseAttack();
        virtual ~BaseAttack();
        
        virtual void attack(Unit& attacker, Unit& victim);
        virtual void counterAttack(Unit& attacker, Unit& victim);
};

#endif // ATTACK_H
