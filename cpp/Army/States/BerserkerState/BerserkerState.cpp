#include "BerserkerState.h"

BerserkerState::BerserkerState(int hp, int dmg) :
                    State(hp, dmg) {
    debugPrint("BerserkerState created");
}
BerserkerState::~BerserkerState() {
    debugPrint("BerserkerState destroyed");
}

void BerserkerState::takeMagicDamage(int dmg) {
    std::cout <<"Berserker says - \"Ha-Ha\"" << std::endl;
}
