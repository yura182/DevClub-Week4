#include "WerewolfState.h"

WerewolfState::WerewolfState(int hp, int dmg) :
                    State(hp, dmg) {
    debugPrint("WerewolfState created");
}
WerewolfState::~WerewolfState() {
    debugPrint("WerewolfState destroyed");
}

void WerewolfState::transform(Unit& unit) {
    if ( !unit.isAlive() ) {
        std::cout << "Unit " << unit.getName() << " is dead" << std::endl;
    }
    
    int newHp = unit.getState().getHitPointsLimit() * TRANSFORM_COEF;
    int newDmg = unit.getState().getDamage() * TRANSFORM_COEF;
    
    unit.setAltState(&unit.getState());
    unit.setState(new WolfState(newHp, newDmg));
    unit.setType(UnitType::WOLF);
    
    std::cout << "\033[35m" << unit.getName() << " transformed into " << unit.getType() << "\033[30m" << std::endl;
}
