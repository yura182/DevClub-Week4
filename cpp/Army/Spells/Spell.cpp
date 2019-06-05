#include "Spell.h"

Spell::Spell(const std::string& name, int manaCost, int damage, SpellType type) {
    this->name = name;
    this->manaCost = manaCost;
    this->damage = damage;
    this->type = type;
    
    debugPrint("Spell created", this->name);
}
Spell::~Spell() {
    debugPrint("Spell destroyed", this->name);
}

const std::string& Spell::getName() const {
    return this->name;
}
int Spell::getManaCost() const {
    return this->manaCost;
}
int Spell::getDamage() const {
    return this->damage;
}

SpellType Spell::getType() const {
    return this->type;
}

Unit* Spell::summon() const {}

std::ostream& operator<<(std::ostream& out, const Spell& spell) {
    SpellType type = spell.getType();
    
    out << spell.getName() << " [";
    out << "mana:" << spell.getManaCost();
    
    if ( type == SpellType::DMG ) {
        out << ", dmg:" << spell.getDamage() << "]";
    } else if ( type == SpellType::HEAL ){
        out << ", heal:" << spell.getDamage() << "]";
    } else if ( type == SpellType::SUMMON ) {
        out << "]";
    }
    
    return out;
}
