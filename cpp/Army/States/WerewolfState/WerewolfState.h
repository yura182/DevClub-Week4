#ifndef WEREWOLFSTATES_H
#define WEREWOLFSTATES_H

#include "../../Helpers/Debug.h"
#include "../State.h"
#include "../WolfState/WolfState.h"


class WerewolfState : public State {
    public:
        WerewolfState(int hp, int dmg);
        ~WerewolfState();
};

#endif // WEREWOLFSTATES_H
