#ifndef ROGUE_H
#define ROGUE_H

#include "../../Helpers/Debug.h"
#include "../Unit.h"
#include "../../States/State.h"
#include "../../Attacks/RogueAttack/RogueAttack.h"

class Rogue : public Unit {
    public:
        Rogue(const std::string& name, int hp=intVal(Health::ROGUE), int dmg=intVal(Damage::ROGUE));
        ~Rogue();
};


#endif // ROGUE_H
