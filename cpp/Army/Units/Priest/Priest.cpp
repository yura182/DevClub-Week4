#include "Priest.h"

Priest::Priest(const std::string& name, int mana, int hp, int dmg)
             : SpellCaster(name,
               new State(hp, dmg),
               new SpellCasterState(mana),
               new PriestAttack(),
               new SpellBook(),
               UnitType::PRIEST,
               UnitType::ALIVE,
               new PriestCast()) {
    this->spellBook->insertSpell(new Fireball());
    this->spellBook->insertSpell(new MagicArrow());
    this->spellBook->insertSpell(new Cure());
    
    debugPrint("Priest created", this->name);
}

Priest::~Priest() {
    debugPrint("Priest destroyed", this->name);
}
