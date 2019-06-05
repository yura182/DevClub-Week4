#ifndef SOLDIER_H
#define SOLDIER_H

#include "../../Helpers/Debug.h"
#include "../Unit.h"
#include "../../States/State.h"

class Soldier : public Unit {
    public:
        Soldier(const std::string& name, int hp=intVal(Health::SOLDIER), int dmg=intVal(Damage::SOLDIER));
        virtual ~Soldier();
};

#endif // SOLDIER_H
