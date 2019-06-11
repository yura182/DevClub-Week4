#include "Berserker.h"

Berserker::Berserker(const std::string& name, int hp, int dmg) 
                : Unit(name,
                  new BerserkerState(hp, dmg),
                  new BaseAttack(),
                  UnitType::BERSERKER,
                  UnitType::ALIVE) {
    
    debugPrint("Berserker created", this->name);
}
Berserker::~Berserker() {
    debugPrint("Berserker destroyed", this->name);
}
