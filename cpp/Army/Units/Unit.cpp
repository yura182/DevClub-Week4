#include "Unit.h"

Unit::Unit(const std::string& name, State *state, BaseAttack *bAttack, UnitType type, UnitType stateType, Ability *ability) {
    this->name = name;
    this->state = state;
    this->baseAttack = bAttack;
    this->type = type;
    this->stateType = stateType;
    this->altState = NULL;
    this->ability = ability;
    
    debugPrint("Unit created", this->name);
}

Unit::~Unit() {
    delete this->state;
    delete this->baseAttack;
    
    if ( this->altState ) {
        delete this->altState;
    }
    if ( this->ability ) {
        delete this->ability;
    }
    
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

State& Unit::getState() const {
    return *(this->state);
}

State& Unit::getAltState() const {
    return *(this->altState);
}

int Unit::getDamage() const {
    return this->state->getDamage();
}


UnitType Unit::getType() const {
    return this->type;
}

UnitType Unit::getStateType() const {
    return this->stateType;
}

BaseAttack* Unit::getAttack() const {
    return this->baseAttack;
}

Ability* Unit::getAbility() const {
    return this->ability;
}

void Unit::addHitPoints(int hp) {
    if ( !isAlive() ) {
        std::cout << "Unit " << this->name << " is dead" << std::endl;
        return;
    }
    
    this->state->addHitPoints(hp);
}

void Unit::setName(const std::string& name) {
    this->name = name;
}

void Unit::takeDamage(int dmg) {
    if ( !isAlive() ) {
        std::cout << "Unit " << this->name << " is dead" << std::endl;
        return;
    }
    
    this->state->takeDamage(dmg);
}

void Unit::takeMagicDamage(int dmg) {
    if ( !isAlive() ) {
        std::cout << "Unit " << this->name << " is dead" << std::endl;
        return;
    }
    
    this->state->takeMagicDamage(dmg);
    
    if ( !this->isAlive() ) {
        this->notify();
    }
}

void Unit::attack(Unit& enemy) {
    if ( !isAlive() ) {
        std::cout << "Unit " << this->name << " is dead and can't attack" << std::endl;
        return;
    }
    
    if ( &enemy == this ) {
        std::cout << "Self attack!" << std::endl;
        return;
    }
    
    this->baseAttack->attack(*this, enemy);
}
void Unit::counterAttack(Unit& enemy) {
    this->baseAttack->counterAttack(*this, enemy);
}

void Unit::useAbility() {
    if ( !isAlive() ) {
        std::cout << "Unit " << this->name << " is dead" << std::endl;
        return;
    }
    
    if ( this->ability ) {
        this->ability->useSelfAbility(*this);
    } else {
        std::cout << this->name << " " << this->type << " dont have ability" << std::endl;
    }
}

void Unit::useAbility(Unit& unit) {
    if ( !isAlive() ) {
        std::cout << "Unit " << this->name << " is dead" << std::endl;
        return;
    }
    
    if ( this->ability ) {
        this->ability->useAbility(unit);
    } else {
        std::cout << this->name << " " << this->type << " dont have ability" <<  std::endl;
    }
}

void Unit::addObserver(Observer *observer) {
    std::set<Observer*>::iterator it = this->observers.find(observer);
    
    if ( it == this->observers.end() ) {
        this->observers.insert(observer);
        
        debugPrint("Added observer", this->name);
    }
}

void Unit::removeObserver(Observer *observer) {
    std::set<Observer*>::iterator it = this->observers.find(observer);
    
    if ( it != this->observers.end() ) {
        this->observers.erase(it);
    }
}

void Unit::notify() {
    if ( !this->observers.empty() ) {
        std::set<Observer*>::iterator it = this->observers.begin();
        int partHp = this->getState().getHitPointsLimit() * PART_HP_NECR;
        
        debugPrint("Notified observers", this->name);
        
        for ( ; it != this->observers.end(); it++ ) {
            (*it)->update(partHp);
        }
    }
}

void Unit::setType(UnitType type) {
    this->type = type;
}

void Unit::setStateType(UnitType type) {
    this->stateType = type;
}

void Unit::setAttack(BaseAttack *attack) {
    this->baseAttack = attack;
}

void Unit::setState(State *state) {
    this->state = state;
}

void Unit::setAltState(State *state) {
    this->altState = state;
}

void Unit::setAbility(Ability *ability) {
    this->ability = ability;
}

std::ostream& operator<<(std::ostream& out, const Unit& unit) {
    out << "\033[30m" << unit.getName();
    out << " " << unit.getType();
    out << " [";
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
        case UnitType::VAMPIRE:
            out << "Vampire";
            break;
        case UnitType::WEREWOLF:
            out << "Werewolf";
            break;
        case UnitType::WOLF:
            out << "Wolf";
            break;
        case UnitType::WIZARD:
            out << "Wizard";
            break;
        case UnitType::HEALER:
            out << "Healer";
            break;
        case UnitType::PRIEST:
            out << "Priest";
            break;
        case UnitType::WARLOCK:
            out << "Warlock";
            break;
        case UnitType::DEMON:
            out << "Demon";
            break;
        case UnitType::NECROMANCER:
            out << "Necromancer";
            break;
        default:
            out << "Unknown";
            break;
    }
    return out;
}
