#ifndef BERSERKER_H
#define BERSERKER_H

#include "../../Helpers/Debug.h"
#include "../Unit.h"
#include "../../States/BerserkerState/BerserkerState.h"

class Berserker : public Unit {
    public:
        Berserker(const std::string&, int x, int y, int hp=intVal(Health::BERSERKER), int dmg=intVal(Damage::BERSERKER));
        ~Berserker();
};

#endif // BERSERKER_H
