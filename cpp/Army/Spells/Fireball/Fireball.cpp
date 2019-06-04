#include "Fireball.h"

Fireball::Fireball() : Spell("Fireball", intVal(SpellCost::FIREBALL), intVal(SpellDmg::FIREBALL)) {
    debugPrint("Fireball created");
}
Fireball::~Fireball() {
    debugPrint("Fireball destroyed");
}
