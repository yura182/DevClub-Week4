#include "Rogue.h"

Rogue::Rogue(const std::string& name, int hp, int dmg) 
                : Unit(name, new State(hp, dmg), new RogueAttack(),
                  UnitType::ROGUE) {
    
    debugPrint("Rogue created", this->name);
}
Rogue::~Rogue() {
    debugPrint("Rogue destroyed", this->name);
}
