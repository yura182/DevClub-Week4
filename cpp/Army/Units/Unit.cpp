#include "Unit.h"

Unit::Unit(const std::string& name, State *state, BaseAttack *bAttack, UnitType type) {
    this->name = name;
    this->state = state;
    this->baseAttack = bAttack;
    this->type = type;
    
    debugPrint("Unit created", this->name);
}

Unit::~Unit() {
    delete this->state;
    delete this->baseAttack;
    
    debugPrint("Unit destroyed", this->name);
}

bool Unit::isAlive() {
    return this->state->getHitPoints() > 0;
}

void Unit::esureIsAlive() {
    if ( !isAlive() ) {
        throw UnitIsDead();
    }
}

const std::string& Unit::getName() const {
    return this->name;
}

const State& Unit::getState() const {
    return *(this->state);
}

int Unit::getDamage() const {
    return this->state->getDamage();
}


UnitType Unit::getType() const {
    return this->type;
}

void Unit::addHitPoints(int hp) {
    if ( !isAlive() ) {
        std::cout << "Unit " << this->name << " is dead" << std::endl;
        return;
    }
    
    this->state->addHitPoints(hp);
}

void Unit::takeDamage(int dmg) {
    if ( !isAlive() ) {
        std::cout << "Unit " << this->name << " is dead" << std::endl;
        return;
    }
    
    this->state->takeDamage(dmg);
}

void Unit::attack(Unit& enemy) {
    if ( !isAlive() ) {
        std::cout << "Unit " << this->name << " is dead and can't attack" << std::endl;
        return;
    }
    
    this->baseAttack->attack(*this, enemy);
}
void Unit::counterAttack(Unit& enemy) {
    this->baseAttack->counterAttack(*this, enemy);
}

std::ostream& operator<<(std::ostream& out, const Unit& unit) {
    out << "\033[30m" << unit.getName() << " " << unit.getType() << " [";
    out << unit.getState() << "]";
    return out;
}

std::ostream& operator<<(std::ostream& out, const UnitType& type) {
    switch (type) {
        case UnitType::SOLDIER:
            out << "Soldier";
            break;
        case UnitType::ROGUE:
            out << "Rogue";
            break;
        case UnitType::BERSERKER:
            out << "Berserker";
            break;
        default:
            out << "Unknown";
            break;
    }
    return out;
}
