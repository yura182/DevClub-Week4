#include "Wizard.h"

Wizard::Wizard(const std::string& name, int hp, int dmg, int mana)
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
