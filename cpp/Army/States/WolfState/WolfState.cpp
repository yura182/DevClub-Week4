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

void WolfState::transform(Unit& unit) {
    if ( !unit.isAlive() ) {
        std::cout << "Unit " << unit.getName() << " is dead" << std::endl;
    }
    
    State *temp = &unit.getState();
    
    unit.setState(&unit.getAltState());
    unit.setAltState(temp);
    unit.setType(UnitType::WEREWOLF);
    
    std::cout << "\033[35m" << unit.getName() << " transformed into " << unit.getType() << "\033[30m" << std::endl;
}
