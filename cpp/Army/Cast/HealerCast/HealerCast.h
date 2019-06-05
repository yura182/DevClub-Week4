#ifndef HEALERCAST_H
#define HEALERCAST_H

#include "../Cast.h"

class HealerCast : public Cast {
    public:
        HealerCast();
        ~HealerCast();
        
        void action(Unit& unit, Spell& spell);
};

#endif // HEALERCAST_H
