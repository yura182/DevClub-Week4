#ifndef WEREWOLF_H
#define WEREWOLF_H

#include "../../Helpers/Debug.h"
#include "../Unit.h"
#include "../../States/State.h"
#include "../../Attacks/WerewolfAttack/WerewolfAttack.h"
#include "../../States/WerewolfState/WerewolfState.h"
#include "../../Abilities/WerewolfAbility/WerewolfAbility.h"

class Werewolf : public Unit {
    public:
        Werewolf(const std::string& name, int hp=intVal(Health::WEREWOLF), int dmg=intVal(Damage::WEREWOLF));
        ~Werewolf();
};

#endif // WEREWOLF_H
