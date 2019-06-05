#include "Fireball.h"

Fireball::Fireball() : Spell("Fireball", intVal(SpellCost::FIREBALL), intVal(SpellDmg::FIREBALL), SpellType::DMG) {
    debugPrint("Fireball created");
}
Fireball::~Fireball() {
    debugPrint("Fireball destroyed");
}
