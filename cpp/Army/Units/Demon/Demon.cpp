#include "Demon.h"

Demon::Demon(const std::string& name, int hp, int dmg) : Soldier(name, hp, dmg) {
    this->type = UnitType::DEMON;
    debugPrint("Demon created", this->name);
}
Demon::~Demon() {
    debugPrint("Demon destroyed", this->name);
}

