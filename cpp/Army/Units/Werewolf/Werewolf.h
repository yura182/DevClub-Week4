#ifndef WEREWOLF_H
#define WEREWOLF_H

#define TRANSFORM_COEF 2

#include "../../Debug/Debug.h"
#include "../Unit.h"
#include "../../States/State.h"

class Werewolf : public Unit {
    public:
        Werewolf(const std::string& name, int hp, int dmg);
        ~Werewolf();
        
        void useAbility();
        void transform();
};

#endif // WEREWOLF_H
