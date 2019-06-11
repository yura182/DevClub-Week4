#include "Vampire.h"

Vampire::Vampire(const std::string& name, int hp, int dmg) 
                : Unit(name,
                  new State(hp, dmg, (int)(hp * HP_LIMIT_COEFF_VAM)),
                  new VampireAttack(),
                  UnitType::VAMPIRE,
                  UnitType::UNDEAD,
                  new VampireAbility()) {
    
    debugPrint("Vampire created", this->name);
}

Vampire::~Vampire() {
    debugPrint("Vampire destroyed", this->name);
}
