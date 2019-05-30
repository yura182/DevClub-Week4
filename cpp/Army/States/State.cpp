#include "State.h"

State::State(int hp, int dmg) {
    this->hitPoints = hp;
    this->hitPointsLimit = hp;
    this->damage = dmg;
    
    debugPrint("State created");
}

State::~State() {
    debugPrint("State destroyed");
}

int State::getDamage() const {
    return this->damage;
}
int State::getHitPoints() const {
    return this->hitPoints;
}
int State::getHitPointsLimit() const {
    return this->hitPointsLimit;
}

void State::addHitPoints(int hp) {
    int freeHitPoints = this->hitPointsLimit - this->hitPoints;
    
    if ( hp > freeHitPoints ) {
        hp = freeHitPoints;
    }
    
    this->hitPoints += hp;
}

void State::takeDamage(int dmg) {
    if ( dmg > this->hitPoints ) {
        this->hitPoints = 0;
    } else {
        this->hitPoints -= dmg;
    }
}

void State::takeMagicDamage(int dmg) {
    this->takeDamage(dmg);
    
    debugPrint("Unit take Magic Damage");
}

std::ostream& operator<<(std::ostream& out, const State& state) {
    out << "hp:" << state.getHitPoints();
    out << " dmg:" << state.getDamage();
    return out;
}

