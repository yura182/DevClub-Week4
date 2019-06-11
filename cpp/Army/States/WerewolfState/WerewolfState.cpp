#include "WerewolfState.h"

WerewolfState::WerewolfState(int hp, int dmg) :
                    State(hp, dmg) {
    debugPrint("WerewolfState created");
}
WerewolfState::~WerewolfState() {
    debugPrint("WerewolfState destroyed");
}

