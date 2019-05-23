#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "../../Debug/Debug.h"
#include "../Unit.h"
#include "../../States/State.h"
#include "../../Attacks/VampireAttack/VampireAttack.h"

class Vampire : public Unit {
    public:
        Vampire(const std::string& name, int hp, int dmg);
        ~Vampire();
};

#endif // VAMPIRE_H
