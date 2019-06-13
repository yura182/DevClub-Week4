#ifndef WARLOCKATTACK_H
#define WARLOCKATTACK_H

#include "../../Helpers/Debug.h"
#include "../../Units/Unit.h"
#include "../../Units/Warlock/Warlock.h"
#include "../BaseAttack.h"

class WarlockAttack : public BaseAttack {
    public:
        WarlockAttack();
        ~WarlockAttack();
        
        void attack(Unit& attacker, Unit& victim);
};

#endif // WARLOCKATTACK_H
