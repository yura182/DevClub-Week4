#include "Healer.h"

Healer::Healer(const std::string& name, int x, int y, int mana, int hp, int dmg)
             : SpellCaster(name, x, y,
               new State(hp, dmg),
               new SpellCasterState(mana),
               new BaseAttack(),
               new SpellBook(),
               UnitType::HEALER,
               UnitType::ALIVE,
               new HealerCast()) {
    this->spellBook->insertSpell(new Fireball());
    this->spellBook->insertSpell(new MagicArrow());
    this->spellBook->insertSpell(new Cure());
    
    debugPrint("Healer created", this->name);
}

Healer::~Healer() {
    debugPrint("Healer destroyed", this->name);
}
