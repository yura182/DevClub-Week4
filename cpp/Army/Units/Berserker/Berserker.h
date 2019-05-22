#ifndef BERSERKER_H
#define BERSERKER_H

#include "../../Debug/Debug.h"
#include "../Unit.h"
#include "../../States/State.h"

class Berserker : public Unit {
    public:
        Berserker(const std::string& name, int hp, int dmg);
        ~Berserker();
};

#endif // BERSERKER_H
