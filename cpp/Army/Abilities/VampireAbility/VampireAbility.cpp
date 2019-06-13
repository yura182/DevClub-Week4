#include "VampireAbility.h"

VampireAbility::VampireAbility() {
    debugPrint("Vampire Ability created");
}
VampireAbility::~VampireAbility() {
    debugPrint("Vampire Ability destroyed");
}

void VampireAbility::useAbility(Unit& unit) {
    infect(unit);
}

void VampireAbility::infect(Unit& unit) {
    std::cout << "Vampire try to infect " << unit.getName() << " " << unit.getType() << std::endl;
    
    if ( !unit.isAlive() ) {
        std::cout << unit.getName() << " is dead and can't transform" << std::endl;
        return;
    } else if ( unit.getType() == UnitType::WEREWOLF ||
                unit.getType() == UnitType::WOLF ||
                unit.getType() == UnitType::VAMPIRE ) {
        std::cout << unit.getName() << " " << unit.getType() << " can't transform into Vampire" << std::endl;
        return;
    }
    
    int newHp = unit.getState().getHitPoints();
    int newHpLimit = (int)unit.getState().getHitPointsLimit() * HP_LIMIT_COEFF_VAM;
    int newDmg = unit.getState().getDamage();
    
    if ( isSpellCaster(unit) ) {
        infectSpellCaster(unit);
    }
    
    unit.setType(UnitType::VAMPIRE);
    unit.setStateType(UnitType::UNDEAD);
    
    delete(unit.getAttack());
    delete(&(unit.getState()));
    
    unit.setAttack(new VampireAttack());
    unit.setState(new State(newHp, newDmg, newHpLimit));
    unit.setAbility(new VampireAbility());
    
    std::cout << "\033[35m" << unit.getName() << " transformed into Vampire" << "\033[30m" << std::endl;
}

void VampireAbility::infectSpellCaster(Unit& unit) {
    SpellCaster &spellCaster = dynamic_cast<SpellCaster&>(unit);
    spellCaster.setCantCast();
}

void VampireAbility::useSelfAbility(Unit& unit) {
    std::cout << unit.getName() << " " << unit.getType() << " don't have this ability" << std::endl;
}
