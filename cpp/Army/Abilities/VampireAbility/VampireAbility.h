#ifndef VAMPIREABILITY_H
#define VAMPIREABILITY_H

#include "../../Helpers/Debug.h"
#include "../Ability.h"
#include "../../Attacks/VampireAttack/VampireAttack.h"
#include "../../Units/Vampire/Vampire.h"
#include "../../States/State.h"
#include "../../Units/SpellCaster.h"
#include "../../Units/Unit.h"

class Unit;

class VampireAbility : public Ability {
    public:
        VampireAbility();
        ~VampireAbility();
        
        void useAbility(Unit& unit);
        void useSelfAbility(Unit& unit);
        void infect(Unit& unit);
};

#endif // VAMPIREABILITY_H
