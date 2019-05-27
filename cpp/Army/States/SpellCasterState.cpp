#include "SpellCasterState.h"

SpellCasterState::SpellCasterState(int mana) {
    this->mana = mana;
    this->manaLimit = mana;
    
    debugPrint("SpellCasterState created");
}

SpellCasterState::~SpellCasterState() {
    debugPrint("SpellCasterState destroyed");
}

int SpellCasterState::getMana() const {
    return this->mana;
}
int SpellCasterState::getManaLimit() const {
    return this->manaLimit;
}

void SpellCasterState::addMana(int mana) {
    int freeMana = this->manaLimit - this->mana;
    
    if ( mana > freeMana ) {
        mana = freeMana;
    }
    
    this->mana += mana;
}

std::ostream& operator<<(std::ostream& out, const SpellCasterState& sCaster) {
    out << " mana:" << sCaster.getMana();
    return out;
}