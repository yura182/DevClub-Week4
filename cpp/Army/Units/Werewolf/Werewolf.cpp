#include "Werewolf.h"

Werewolf::Werewolf(const std::string& name, int hp, int dmg) 
                : Unit(name,
                  new WerewolfState(hp, dmg),
                  new BaseAttack(),
                  UnitType::WEREWOLF,
                  UnitType::ALIVE) {
    
    debugPrint("Werewolf created", this->name);
}
Werewolf::~Werewolf() {
    debugPrint("Werewolf destroyed", this->name);
}

void Werewolf::useAbility() {
    this->state->transform(*this);
}
