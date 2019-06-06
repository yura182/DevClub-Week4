#include "Vampire.h"

Vampire::Vampire(const std::string& name, int hp, int dmg) 
                : Unit(name,
                  new State(hp, dmg, (int)(hp * HP_LIMIT_COEFF_VAM)),
                  new VampireAttack(),
                  UnitType::VAMPIRE,
                  UnitType::UNDEAD) {
    
    debugPrint("Vampire created", this->name);
}

Vampire::~Vampire() {
    debugPrint("Vampire destroyed", this->name);
}

void Vampire::useAbility(Unit& unit) {
    transformIntoVampire(unit);
}

void Vampire::transformIntoVampire(Unit& unit) {
    if ( !unit.isAlive() ) {
        std::cout << unit.getName() << " is dead and can't transform" << std::endl;
        return;
    } else if ( unit.getType() == UnitType::WEREWOLF ||
                unit.getType() == UnitType::WOLF ||
                unit.getType() == UnitType::VAMPIRE ) {
        std::cout << unit.getName() << " " << unit.getType() << " can't transform into Vampire" << std::endl;
        return;
    }
    
    unit.getState().setDamage(this->getDamage());
    unit.getState().setHitPointsLimit(this->getState().getHitPointsLimit());
    unit.setType(UnitType::VAMPIRE);
    unit.setStateType(UnitType::UNDEAD);
    delete(unit.getAttack());
    unit.setAttack(new VampireAttack());
    
    std::cout << "\033[35m" << unit.getName() << " transformed into Vampire" << "\033[30m" << std::endl;
}
