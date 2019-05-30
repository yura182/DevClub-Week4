#ifndef CAST_H
#define CAST_H

#include "../Helpers/Debug.h"
#include "../Units/Unit.h"
#include "../Spells/Spell.h"

class Unit;
class Spell;

class Cast {
    public:
        Cast();
        ~Cast();
        
        void action(Unit& unit, Spell& spell);
};

#endif // CAST_H
