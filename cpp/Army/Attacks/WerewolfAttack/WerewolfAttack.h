#ifndef WEREWOLFATTACK_H
#define WEREWOLFATTACK_H

#include "../../Helpers/Debug.h"
#include "../../Units/Unit.h"
#include "../BaseAttack.h"

class WerewolfAttack : public BaseAttack {
    public:
        WerewolfAttack();
        ~WerewolfAttack();
        
        void attack(Unit& attacker, Unit& victim);
        void counterAttack(Unit& attacker, Unit& victim);
};

#endif // WEREWOLFATTACK_H
