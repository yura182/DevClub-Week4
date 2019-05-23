#ifndef VAMPIREATTACK_H
#define VAMPIREATTACK_H

#define PART_OF_HP 0.6

#include "../../Debug/Debug.h"
#include "../../Units/Unit.h"
#include "../BaseAttack.h"

class VampireAttack : public BaseAttack {
    public:
        VampireAttack();
        ~VampireAttack();
        
        void attack(Unit& attacker, Unit& victim);
        void counterAttack(Unit& attacker, Unit& victim);
};

#endif // VAMPIREATTACK_H
