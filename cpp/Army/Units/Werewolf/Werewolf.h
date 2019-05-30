#ifndef WEREWOLF_H
#define WEREWOLF_H

#define TRANSFORM_COEF 2

#include "../../Helpers/Debug.h"
#include "../Unit.h"
#include "../../States/State.h"
#include "../../States/WolfState/WolfState.h"

class Werewolf : public Unit {
    public:
        Werewolf(const std::string& name, int hp=intVal(Health::WEREWOLF), int dmg=intVal(Damage::WEREWOLF));
        ~Werewolf();
        
        void useAbility();
        void transform();
};

#endif // WEREWOLF_H
