#include "SummonDemon.h"

SummonDemon::SummonDemon() : Spell("Summon Demon", intVal(SpellCost::SUMMONDEMON), 0, SpellType::SUMMON) {
    debugPrint("SummonDemon created");
}
SummonDemon::~SummonDemon() {
    debugPrint("SummonDemon destroyed");
}

Unit* SummonDemon::summon() const {
    Unit *demon = new Demon("Demon");
    
    return demon;
}
