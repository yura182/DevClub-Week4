#include "Rogue.h"

Rogue::Rogue(const std::string& name, int x, int y, int hp, int dmg) 
                : Unit(name, x, y,
                  new State(hp, dmg),
                  new RogueAttack(),
                  UnitType::ROGUE,
                  UnitType::ALIVE) {
    
    debugPrint("Rogue created", this->name);
}
Rogue::~Rogue() {
    debugPrint("Rogue destroyed", this->name);
}
