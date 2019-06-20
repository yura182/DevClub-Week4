#ifndef SUMMONDEMON_H
#define SUMMONDEMON_H

#include "../../Helpers/Debug.h"
#include "../Spell.h"
#include "../../Units/Unit.h"
#include "../../Units/Demon/Demon.h"

class SummonDemon : public Spell {
    public:
        SummonDemon();
        ~SummonDemon();
        
        Unit* summon(int x, int y) const;
};

#endif // SUMMONDEMON_H
