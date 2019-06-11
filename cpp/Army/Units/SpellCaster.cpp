#include "SpellCaster.h"

SpellCaster::SpellCaster(const std::string& name,
                         State *state,
                         SpellCasterState *scState,
                         BaseAttack *bAttack, SpellBook *spellBook,
                         UnitType type, UnitType stateType, Cast *cast)
                       : Unit(name, state, bAttack, type, stateType) {
    this->scState = scState;
    this->spellBook = spellBook;
    this->cast = cast;
    this->canCast = true;
    
    debugPrint("SpellCaster created", this->name);
}

SpellCaster::~SpellCaster() {
    delete this->scState;
    delete this->spellBook;
    delete this->cast;
    
    debugPrint("SpellCaster destroyed", this->name);
}

SpellCasterState& SpellCaster::getScState() const {
    return *(this->scState);
}

int SpellCaster::getMana() const {
    return this->scState->getMana();
}

SpellBook& SpellCaster::getSpellBook() const {
    return *(this->spellBook);
}

Spell& SpellCaster::getSpell(const std::string name) const {
    return this->spellBook->getSpell(name);
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
    
    // if ( !this->canCast ) {
    //     std::cout << "Unit " << this->name << " can't cast anymore" << std::endl;
    //     return;
    // }
    
    if ( !haveMana() ) {
        std::cout << "Unit " << this->name << " don't have mana" << std::endl;
        return;
    }
    
    if ( !haveEnoughMana(spell) ) {
        std::cout << "Unit " << this->name << " don't have enough mane for " <<spell.getName() << " spell" << std::endl;
        return;
    }
    
    if ( &unit == this ) {
        std::cout << "Self cast!" << std::endl;
        return;
    }
    
    std::cout << "\033[31m" << this->getName() << " " << this->getType() << " casted spell " << spell.getName() << " to " << unit.getName() << " " << unit.getType() << "\033[30m" << std::endl;
    
    this->cast->action(unit, spell);
    
    this->scState->reduceMana(spell.getManaCost());
}

void SpellCaster::castAction(Spell& spell) {}

void SpellCaster::showSpellBook() const {
    std::cout << "\033[32m" << "---- " << this->getName() << "'s Spell Book ----" << std::endl;
    std::cout << this->getSpellBook() << "\033[30m" << std::endl;
}

void SpellCaster::showSpecial() const {}

void SpellCaster::setCantCast() {
    this->canCast = false;
}

std::ostream& operator<<(std::ostream& out, const SpellCaster& sCaster) {
    out << "\033[30m" << sCaster.getName() << " " << sCaster.getType() << " [";
    out << sCaster.getState() << sCaster.getScState() << "]";
    return out;
}

bool isSpellCaster(Unit& unit) {
    if ( unit.getType() == UnitType::WIZARD ||
         unit.getType() == UnitType::HEALER ||
         unit.getType() == UnitType::PRIEST ||
         unit.getType() == UnitType::WARLOCK ||
         unit.getType() == UnitType::NECROMANCER ) {
        return true;
    } else {
        return false;
    }
}
