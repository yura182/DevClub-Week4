#ifndef ROGUE_H
#define ROGUE_H

#include "../../Debug/Debug.h"
#include "../Unit.h"
#include "../../States/State.h"
#include "../../Attacks/RogueAttack/RogueAttack.h"

class Rogue : public Unit {
    public:
        Rogue(const std::string& name, int hp, int dmg);
        ~Rogue();
};


#endif // ROGUE_H
