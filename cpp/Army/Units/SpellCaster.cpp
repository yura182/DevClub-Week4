#include "SpellCaster.h"

SpellCaster::SpellCaster(const std::string& name,
                         State *state,
                         SpellCasterState *scState,
                         BaseAttack *bAttack,
                         UnitType type)
                       : Unit(name, state, bAttack, type) {
    this->scState = scState;
    
    debugPrint("SpellCaster created", this->name);
}

SpellCaster::~SpellCaster() {
    delete this->scState;
    
    debugPrint("SpellCaster destroyed", this->name);
}

SpellCasterState& SpellCaster::getScState() const {
    return *(this->scState);
}

int SpellCaster::getMana() const {
    return this->scState->getMana();
}

void SpellCaster::addMana(int mana) {
    if ( !isAlive() ) {
        std::cout << "Unit " << this->name << " is dead" << std::endl;
        return;
    }
    
    this->scState->addMana(mana);
}

std::ostream& operator<<(std::ostream& out, const SpellCaster& sCaster) {
    out << "\033[30m" << sCaster.getName() << " " << sCaster.getType() << " [";
    out << sCaster.getState() << sCaster.getScState() << "]";
    return out;
}
