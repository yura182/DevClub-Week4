#include "Cure.h"

Cure::Cure() : Spell("Cure", intVal(SpellCost::CURE), intVal(SpellDmg::CURE), SpellType::HEAL) {
    debugPrint("Cure created");
}
Cure::~Cure() {
    debugPrint("Cure destroyed");
}
