#ifndef ABILITY_H
#define ABILITY_H

#include "../Helpers/Debug.h"
#include "../Units/Unit.h"

class Ability {
    public:
        Ability() { debugPrint("Ability created"); };
        virtual ~Ability() { debugPrint("Ability destroyed"); }
        
        virtual void useAbility(Unit& unit) = 0;
        virtual void useSelfAbility(Unit& unit) = 0;
};

#endif // ABILITY_H
