#include "WolfState.h"

WolfState::WolfState(int hp, int dmg) :
                    State(hp, dmg) {
    debugPrint("WolfState created");
}
WolfState::~WolfState() {
    debugPrint("WolfState destroyed");
}

void WolfState::takeMagicDamage(int dmg) {
    this->takeDamage((int)((float)dmg * WOLF_MAGIC_DMG_COEFF));
    
    debugPrint("Unit take Magic Damage");
}
