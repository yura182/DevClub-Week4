#include "Unit.h"

Unit::Unit(const std::string& name, int hp, int dmg) {
    this->name = name;
    this->state = new State(hp, dmg);
    this->baseAttack = new BaseAttack();
    
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
    out << unit.getName() << " [";
    out << unit.getState() << "]";
    return out;
}
