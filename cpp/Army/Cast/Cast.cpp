#include "Cast.h"

Cast::Cast(){
    debugPrint("Cast created");
}
Cast::~Cast(){
    debugPrint("Cast destroyed");
}

void Cast::action(Unit& unit, Spell& spell){
    unit.takeMagicDamage(spell.getDamage());
}
