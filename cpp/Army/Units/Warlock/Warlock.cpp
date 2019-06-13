#include "Warlock.h"

Warlock::Warlock(const std::string& name, int mana, int hp, int dmg)
             : SpellCaster(name,
               new State(hp, dmg),
               new SpellCasterState(mana),
               new WarlockAttack(),
               new SpellBook(),
               UnitType::WARLOCK,
               UnitType::ALIVE,
               new Cast()) {
    this->spellBook->insertSpell(new Fireball());
    this->spellBook->insertSpell(new SummonDemon());
    this->spellBook->insertSpell(new Cure());
    
    debugPrint("Warlock created", this->name);
}

Warlock::~Warlock() {
    std::set<Unit*>::iterator it = this->demons.begin();
    
    for ( ; it != this->demons.end(); it++ ) {
        delete *it;
    }
    
    debugPrint("Warlock destroyed", this->name);
}

const std::set<Unit*>& Warlock::getDemons() const {
    return this->demons;
}

void Warlock::castAction(Spell& spell) {
    if ( !this->isAlive() ) {
        std::cout << "Unit " << this->name << " is dead and can't cast" << std::endl;
        return;
    }
    
    if ( !this->haveMana() ) {
        std::cout << "Unit " << this->name << " don't have mana" << std::endl;
        return;
    }
    
    if ( !this->haveEnoughMana(spell) ) {
        std::cout << "Unit " << this->name << " don't have enough mana for " <<spell.getName() << " spell" << std::endl;
    }
     
    if ( this->getCanCast() ) {
        Unit *unit = spell.summon();
        std::string newName = this->name;
        
        newName.append("'s slave").append(std::to_string(this->demons.size() + 1));
        
        unit->setName(newName);
        
        this->demons.insert(unit);
        
        this->scState->reduceMana(spell.getManaCost());
        
        std::cout << "\033[31m" << this->getName() << " " << this->getType() << " casted spell " << spell.getName() << " and summoned " << unit->getName() << " " << unit->getType() << "\033[30m" << std::endl;
    } else {
        std::cout << "\033[35m" << "Unit " << this->name << " can't cast anymore" << "\033[30m" << std::endl;
    }
}

void Warlock::showSpecial() const {
    std::cout << "\033[32m" << "---- " << this->getName() << "'s Slaves ----" << std::endl;
    
    if ( this->demons.empty() ) {
        std::cout << this->name << " don't have slaves" << "\033[30m" << std::endl;
    } else {
        std::cout << this->demons << "\033[30m" << std::endl;
    }
}

void Warlock::useAbility() {
    this->castAction(this->getSpell("Summon Demon"));
}

std::ostream& operator<<(std::ostream& out, const std::set<Unit*>& demons) {
    std::set<Unit*>::iterator it = demons.begin();
    
    for ( int i = 1, limit = demons.size(); i < limit; it++, i++ ) {
        out << **it << std::endl;
    }
    out << **it;
    
    return out;
}

