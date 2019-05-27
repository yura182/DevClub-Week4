#include "Soldier.h"

Soldier::Soldier(const std::string& name, int hp, int dmg) 
                : Unit(name, new State(hp, dmg), new BaseAttack(),
                  UnitType::SOLDIER) {
    
    debugPrint("Soldier created", this->name);
}
Soldier::~Soldier() {
    debugPrint("Soldier destroyed", this->name);
}
