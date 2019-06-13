#ifndef WEREWOLFABILITY_H
#define WEREWOLFABILITY_H

#define TRANSFORM_COEF 2

#include "../../Helpers/Debug.h"
#include "../Ability.h"
#include "../../Attacks/WerewolfAttack/WerewolfAttack.h"
#include "../../States/WolfState/WolfState.h"
#include "../../States/WerewolfState/WerewolfState.h"
#include "../../Units/SpellCaster.h"

class WerewolfAbility : public Ability{
    public:
        WerewolfAbility();
        ~WerewolfAbility();
        
        void useAbility(Unit& unit);
        void useSelfAbility(Unit& unit);
        void selfTransform(Unit& unit);
        void infect(Unit& unit);
        void infectSpellCaster(Unit& unit);
};

#endif // WEREWOLFABILITY_H
