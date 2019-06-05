#include "PriestCast.h"

PriestCast::PriestCast() {
    debugPrint("PriestCast created");
}
PriestCast::~PriestCast() {
    debugPrint("PriestCast destroyed");
}

void PriestCast::action(Unit& unit, Spell& spell) {
    if ( spell.getType() == SpellType::DMG ) {
        if ( unit.getStateType() == UnitType::UNDEAD ) {
            unit.takeMagicDamage(spell.getDamage() * 2);
        } else if ( unit.getStateType() == UnitType::ALIVE ){
            unit.takeMagicDamage(spell.getDamage() / 2);
        }
    } else if ( spell.getType() == SpellType::HEAL ) {
        unit.addHitPoints(spell.getDamage());
    }
    
}
