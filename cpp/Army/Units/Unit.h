#ifndef UNIT_H
#define UNIT_H

#define PART_HP_NECR 0.1

#include <iostream>
#include <set>
#include "../Helpers/Exceptions.h"
#include "../Helpers/Debug.h"
#include "../States/State.h"
#include "../Attacks/BaseAttack.h"
#include "../Helpers/Default.h"
#include "../Interfaces/Observable.h"
#include "../Interfaces/Observer.h"
#include "../Abilities/Ability.h"

class State;
class BaseAttack;
class Ability;

enum class UnitType {
    SOLDIER,
    ROGUE,
    BERSERKER,
    VAMPIRE,
    WEREWOLF,
    WOLF,
    DEMON,
    
    WIZARD,
    HEALER,
    PRIEST,
    WARLOCK,
    NECROMANCER,
    
    ALIVE,
    UNDEAD
};

class Unit : public Observable {
    protected:
        std::string name;
        State *state;
        State *altState;
        BaseAttack *baseAttack;
        Ability *ability;
        UnitType type;
        UnitType stateType;
        
        std::set<Observer*> observers;
        
        Unit(const std::string& name, State *state, BaseAttack *bAttack, UnitType type, UnitType stateType, Ability *ability=NULL);
    public:
        virtual ~Unit();
        
        bool isAlive();
        void esureIsAlive();
        
        const std::string& getName() const;
        
        State& getState() const;
        State& getAltState() const;
        
        UnitType getType() const;
        UnitType getStateType() const;
        
        BaseAttack* getAttack() const;
        Ability* getAbility() const;
        
        int getDamage() const;
        
        void addHitPoints(int hp);
        void setName(const std::string& name);
        void takeDamage(int dmg);
        virtual void takeMagicDamage(int dmg);
        
        virtual void attack(Unit& enemy);
        virtual void counterAttack(Unit& enemy);
        
        virtual void useAbility();
        virtual void useAbility(Unit& unit);
        
        virtual void addObserver(Observer *observer);
        virtual void removeObserver(Observer *observer);
        virtual void notify();
        
        void setType(UnitType type);
        void setStateType(UnitType type);
        void setAttack(BaseAttack *attack);
        void setState(State *state);
        void setAltState(State *state);
        void setAbility(Ability *ability);
};

std::ostream& operator<<(std::ostream& out, const Unit& unit);
std::ostream& operator<<(std::ostream& out, const UnitType& type);

#endif // UNIT_H
