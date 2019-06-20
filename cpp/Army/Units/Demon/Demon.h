#ifndef DEMON_H
#define DEMON_H

#include "../../Helpers/Debug.h"
#include "../Unit.h"
#include "../Soldier/Soldier.h"
#include "../../States/State.h"

class Demon : public Soldier {
    public:
        Demon(const std::string& name, int x, int y, int hp=intVal(Health::DEMON), int dmg=intVal(Damage::DEMON));
        ~Demon();
};

#endif // DEMON_H
