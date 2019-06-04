#include "Berserker.h"

Berserker::Berserker(const std::string& name, int hp, int dmg) 
                : Unit(name, new State(hp, dmg), new BaseAttack(),
                  UnitType::BERSERKER) {
    
    debugPrint("Berserker created", this->name);
}
Berserker::~Berserker() {
    debugPrint("Berserker destroyed", this->name);
}

void Berserker::takeMagicDamage(int dmg) {
    std::cout << this->getName() << " " << this->getType() << " says - \"Ha-Ha\"" << std::endl;
}