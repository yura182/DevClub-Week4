#ifndef WEREWOLFSTATES_H
#define WEREWOLFSTATES_H

#include "../../Helpers/Debug.h"
#include "../State.h"
#include "../WolfState/WolfState.h"

#define TRANSFORM_COEF 2

class WerewolfState : public State {
    public:
        WerewolfState(int hp, int dmg);
        ~WerewolfState();
        
        void transform(Unit& unit);
};

#endif // WEREWOLFSTATES_H
