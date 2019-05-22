#ifndef SOLDIER_H
#define SOLDIER_H

#include "../../Debug/Debug.h"
#include "../Unit.h"
#include "../../States/State.h"

class Soldier : public Unit {
    public:
        Soldier(const std::string& name, int hp, int dmg);
        ~Soldier();
};

#endif // SOLDIER_H
