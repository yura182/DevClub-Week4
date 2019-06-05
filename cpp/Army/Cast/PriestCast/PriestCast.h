#ifndef PRIESTCAST_H
#define PRIESTCAST_H

#include "../Cast.h"

class PriestCast : public Cast {
    public:
        PriestCast();
        ~PriestCast();
        
        void action(Unit& unit, Spell& spell);
};

#endif // PRIESTCAST_H
