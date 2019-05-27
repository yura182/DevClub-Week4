#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "../../Helpers/Debug.h"
#include "../Unit.h"
#include "../../States/State.h"
#include "../../Attacks/VampireAttack/VampireAttack.h"

class Vampire : public Unit {
    public:
        Vampire(const std::string& name, int hp=intVal(Health::VAMPIRE), int dmg=intVal(Damage::VAMPIRE));
        ~Vampire();
};

#endif // VAMPIRE_H
