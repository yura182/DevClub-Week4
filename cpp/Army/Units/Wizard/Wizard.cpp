#include "Wizard.h"

Wizard::Wizard(const std::string& name, int mana, int hp, int dmg)
             : SpellCaster(name,
               new State(hp, dmg),
               new SpellCasterState(mana),
               new BaseAttack(),
               UnitType::WIZARD) {
    debugPrint("Wizard created", this->name);
}

Wizard::~Wizard() {
    debugPrint("Wizard destroyed", this->name);
}
