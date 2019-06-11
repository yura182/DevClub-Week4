#ifndef BERSERKERSTATES_H
#define BERSERKERSTATES_H

#include "../../Helpers/Debug.h"
#include "../State.h"

class BerserkerState : public State {
    public:
        BerserkerState(int hp, int dmg);
        ~BerserkerState();
        
        void takeMagicDamage(int dmg);
};

#endif // BERSERKERSTATES_H
