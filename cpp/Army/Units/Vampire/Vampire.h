#ifndef VAMPIRE_H
#define VAMPIRE_H

#define HP_LIMIT_COEFF_VAM 1.6

#include "../../Helpers/Debug.h"
#include "../Unit.h"
#include "../../States/State.h"
#include "../../Attacks/VampireAttack/VampireAttack.h"

class Vampire : public Unit {
    public:
        Vampire(const std::string& name, int hp=intVal(Health::VAMPIRE), int dmg=intVal(Damage::VAMPIRE));
        ~Vampire();
        
        void useAbility(Unit& unit);
        void transformIntoVampire(Unit& unit);
};

#endif // VAMPIRE_H
