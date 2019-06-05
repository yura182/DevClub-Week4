#include "HealerCast.h"

HealerCast::HealerCast(){
    debugPrint("HealerCast created");
}
HealerCast::~HealerCast(){
    debugPrint("HealerCast destroyed");
}

void HealerCast::action(Unit& unit, Spell& spell){
    if ( spell.getType() == SpellType::DMG ) {
        unit.takeMagicDamage(spell.getDamage() / 2);
    } else if ( spell.getType() == SpellType::HEAL ) {
        unit.addHitPoints(spell.getDamage());
    }
    
}
