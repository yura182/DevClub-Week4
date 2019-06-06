#ifndef WEREWOLF_H
#define WEREWOLF_H

#include "../../Helpers/Debug.h"
#include "../Unit.h"
#include "../../States/State.h"
#include "../../States/WolfState/WolfState.h"
#include "../../States/WerewolfState/WerewolfState.h"

class Werewolf : public Unit {
    public:
        Werewolf(const std::string& name, int hp=intVal(Health::WEREWOLF), int dmg=intVal(Damage::WEREWOLF));
        ~Werewolf();
        
        void useAbility();
};

#endif // WEREWOLF_H
