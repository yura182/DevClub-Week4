#include "Werewolf.h"

Werewolf::Werewolf(const std::string& name, int hp, int dmg) 
                : Unit(name,
                  new State(hp, dmg),
                  new BaseAttack(),
                  UnitType::WEREWOLF,
                  UnitType::ALIVE) {
    
    debugPrint("Werewolf created", this->name);
}
Werewolf::~Werewolf() {
    debugPrint("Werewolf destroyed", this->name);
}

void Werewolf::useAbility() {
    transform();
}

void Werewolf::transform() {
    if ( !this->isAlive() ) {
        std::cout << "Unit " << this->name << " is dead" << std::endl;
    }
    
    if ( this->type == UnitType::WEREWOLF ) {
        int newHp = this->state->getHitPointsLimit() * TRANSFORM_COEF;
        int newDmg = this->state->getDamage() * TRANSFORM_COEF;
        
        this->altState = this->state;
        this->state = new WolfState(newHp, newDmg);
        this->type = UnitType::WOLF;
        
        debugPrint("Werewolf transformed", this->name);
    } else if ( this->type == UnitType::WOLF ) {
        State *temp = this->state;
        
        this->state = this->altState;
        this->altState = temp;
        this->type = UnitType::WEREWOLF;
        
        debugPrint("Wolf transformed", this->name);
    }
}

