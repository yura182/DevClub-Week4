#include "SpellCaster.h"

SpellCaster::SpellCaster(const std::string& name,
                         State *state,
                         SpellCasterState *scState,
                         BaseAttack *bAttack, Spell *spell,
                         UnitType type)
                       : Unit(name, state, bAttack, type) {
    this->scState = scState;
    this->spell = spell;
    this->cast = new Cast();
    
    debugPrint("SpellCaster created", this->name);
}

SpellCaster::~SpellCaster() {
    delete this->scState;
    delete this->spell;
    delete this->cast;
    
    debugPrint("SpellCaster destroyed", this->name);
}

SpellCasterState& SpellCaster::getScState() const {
    return *(this->scState);
}

int SpellCaster::getMana() const {
    return this->scState->getMana();
}

Spell& SpellCaster::getSpell() const {
    return *(this->spell);
}

void SpellCaster::addMana(int mana) {
    if ( !isAlive() ) {
        std::cout << "Unit " << this->name << " is dead" << std::endl;
        return;
    }
    
    this->scState->addMana(mana);
}

bool SpellCaster::haveMana() const {
    return this->getMana() > 0;
}

bool SpellCaster::haveEnoughMana(Spell& spell) const {
    return (this->getMana() - spell.getManaCost()) > 0;
}

void SpellCaster::castAction(Unit& unit, Spell& spell) {
    if ( !isAlive() ) {
        std::cout << "Unit " << this->name << " is dead and can't cast" << std::endl;
        return;
    }
    
    if ( !haveMana() ) {
        std::cout << "Unit " << this->name << " don't have mana" << std::endl;
        return;
    }
    
    if ( !haveEnoughMana(spell) ) {
        std::cout << "Unit " << this->name << " don't have enough mane for " <<spell.getName() << " spell" << std::endl;
        return;
    }
    
    std::cout << "\033[31m" << this->getName() << " " << this->getType() << " casted spell " << spell.getName() << " to " << unit.getName() << " " << unit.getType() << "\033[30m" << std::endl;
    
    this->cast->action(unit, spell);
    
    this->scState->reduceMana(spell.getManaCost());
}

std::ostream& operator<<(std::ostream& out, const SpellCaster& sCaster) {
    out << "\033[30m" << sCaster.getName() << " " << sCaster.getType() << " [";
    out << sCaster.getState() << sCaster.getScState() << "]";
    return out;
}
