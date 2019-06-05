#include "Cast.h"

Cast::Cast(){
    debugPrint("Cast created");
}
Cast::~Cast(){
    debugPrint("Cast destroyed");
}

void Cast::action(Unit& unit, Spell& spell) {
    if ( spell.getType() == SpellType::DMG ) {
        unit.takeMagicDamage(spell.getDamage());
    } else if ( spell.getType() == SpellType::HEAL ) {
        unit.addHitPoints(spell.getDamage());
    }
    
}

void Cast::action(Spell& spell) {}
