#include "Necromancer.h"

Necromancer::Necromancer(const std::string& name, int mana, int hp, int dmg)
             : SpellCaster(name,
               new State(hp, dmg, (int)(hp * HP_LIMIT_COEFF_NECR)),
               new SpellCasterState(mana),
               new BaseAttack(),
               new SpellBook(),
               UnitType::NECROMANCER,
               UnitType::UNDEAD,
               new Cast()) {
    this->spellBook->insertSpell(new Fireball());
    this->spellBook->insertSpell(new MagicArrow());
    
    debugPrint("Necromancer created", this->name);
}

Necromancer::~Necromancer() {
    debugPrint("Necromancer destroyed", this->name);
}

void Necromancer::update(int hp) {
    if ( hp > 0 && this->isAlive() ) {
      this->addHitPoints(hp);
      
      std::cout << "\033[35m" << this->name << " " << this->type;
      std::cout << " get " << hp << " hp" << "\033[30m" << std::endl;
    }
}

void Necromancer::attack(Unit& enemy) {
    if ( !isAlive() ) {
        std::cout << "Unit " << this->name << " is dead and can't attack" << std::endl;
        return;
    }
    
    if ( &enemy == this ) {
        std::cout << "Self attack!" << std::endl;
        return;
    }
    
    this->baseAttack->attack(*this, enemy);
    
    if ( enemy.isAlive() ) {
        Observer *observer = this;
        
        enemy.addObserver(observer);
    } else {
        int partHp = enemy.getState().getHitPointsLimit() * PART_HP_NECR;
        
        this->update(partHp);
    }
}

void Necromancer::counterAttack(Unit& enemy) {
    this->baseAttack->counterAttack(*this, enemy);
    
    if ( enemy.isAlive() ) {
        Observer *observer = this;
        
        enemy.addObserver(observer);
    } else {
        int partHp = enemy.getState().getHitPointsLimit() * PART_HP_NECR;
        
        this->update(partHp);
    }
}
