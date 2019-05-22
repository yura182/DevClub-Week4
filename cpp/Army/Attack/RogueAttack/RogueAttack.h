#ifndef ROGUEATTACK_H
#define ROGUEATTACK_H

#include "../../Debug/Debug.h"
#include "../../Units/Unit.h"
#include "../BaseAttack.h"

class RogueAttack : public BaseAttack {
    public:
        RogueAttack();
        ~RogueAttack();
        
        void attack(Unit& attacker, Unit& victim);
};

#endif // ROGUEATTACK_H
