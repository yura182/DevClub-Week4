#ifndef WOLFSTATES_H
#define WOLFSTATES_H

#define WOLF_MAGIC_DMG_COEFF 1.5

#include "../../Helpers/Debug.h"
#include "../State.h"

class WolfState : public State {
    public:
        WolfState(int hp, int dmg);
        ~WolfState();
        
        void takeMagicDamage(int dmg);
};

#endif // WOLFSTATES_H
