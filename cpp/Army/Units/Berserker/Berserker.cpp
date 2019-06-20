#include "Berserker.h"

Berserker::Berserker(const std::string& name, int x, int y, int hp, int dmg) 
                : Unit(name, x, y,
                  new BerserkerState(hp, dmg),
                  new BaseAttack(),
                  UnitType::BERSERKER,
                  UnitType::ALIVE) {
    
    debugPrint("Berserker created", this->name);
}
Berserker::~Berserker() {
    debugPrint("Berserker destroyed", this->name);
}
