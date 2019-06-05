#include "WizardCast.h"

WizardCast::WizardCast(){
    debugPrint("WizardCast created");
}
WizardCast::~WizardCast(){
    debugPrint("WizardCast destroyed");
}

void WizardCast::action(Unit& unit, Spell& spell){
    if ( spell.getType() == SpellType::DMG ) {
        unit.takeMagicDamage(spell.getDamage());
    } else if ( spell.getType() == SpellType::HEAL ) {
        unit.addHitPoints(spell.getDamage() / 2);
    }
    
}
