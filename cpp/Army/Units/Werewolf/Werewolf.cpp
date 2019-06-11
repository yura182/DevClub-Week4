#include "Werewolf.h"

Werewolf::Werewolf(const std::string& name, int hp, int dmg) 
                : Unit(name,
                  new WerewolfState(hp, dmg),
                  new WerewolfAttack(),
                  UnitType::WEREWOLF,
                  UnitType::ALIVE,
                  new WerewolfAbility()) {
    
    debugPrint("Werewolf created", this->name);
}
Werewolf::~Werewolf() {
    debugPrint("Werewolf destroyed", this->name);
}

