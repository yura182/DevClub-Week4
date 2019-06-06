#include "State.h"

State::State(int hp, int dmg, int hpLim) {
    this->hitPoints = randValue(hp);
    if ( hpLim == 0 ) {
        this->hitPointsLimit = this->hitPoints;
    } else {
        this->hitPointsLimit = randValue(hpLim);
    }
    this->damage = randValue(dmg);
    
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

void State::setDamage(int dmg) {
    this->damage = dmg;
}
void State::setHitPoints(int hp) {
    this->hitPoints = hp;
}
void State::setHitPointsLimit(int hpLim) {
    this->hitPointsLimit = hpLim;
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

void State::transform(Unit& unit) {}

std::ostream& operator<<(std::ostream& out, const State& state) {
    out << "hp:" << state.getHitPoints();
    out << " dmg:" << state.getDamage();
    return out;
}

