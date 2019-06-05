#include "Vampire.h"

Vampire::Vampire(const std::string& name, int hp, int dmg) 
                : Unit(name,
                  new State(hp, dmg),
                  new VampireAttack(),
                  UnitType::VAMPIRE,
                  UnitType::UNDEAD) {
    
    debugPrint("Vampire created", this->name);
}

Vampire::~Vampire() {
    debugPrint("Vampire destroyed", this->name);
}
