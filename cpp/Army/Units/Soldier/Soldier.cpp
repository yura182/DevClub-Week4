#include "Soldier.h"

Soldier::Soldier(const std::string& name, int x, int y, int hp, int dmg) 
                : Unit(name, x, y,
                  new State(hp, dmg),
                  new BaseAttack(),
                  UnitType::SOLDIER,
                  UnitType::ALIVE) {
    
    debugPrint("Soldier created", this->name);
}
Soldier::~Soldier() {
    debugPrint("Soldier destroyed", this->name);
}

