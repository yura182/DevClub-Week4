#include "Spell.h"

Spell::Spell(const std::string& name, int manaCost, int damage) {
    this->name = name;
    this->manaCost = manaCost;
    this->damage = damage;
    
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

std::ostream& operator<<(std::ostream& out, const Spell& spell) {
    out << spell.getName() << " [";
    out << "mana:" << spell.getManaCost() << ", ";
    out << "dmg:" << spell.getDamage() << "]";
    return out;
}
