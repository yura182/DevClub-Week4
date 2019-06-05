#include "MagicArrow.h"

MagicArrow::MagicArrow() : Spell("Magic Arrow", intVal(SpellCost::MAGICARROW), intVal(SpellDmg::MAGICARROW), SpellType::DMG) {
    debugPrint("MagicArrow created");
}
MagicArrow::~MagicArrow() {
    debugPrint("MagicArrow destroyed");
}
