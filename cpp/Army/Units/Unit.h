#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include "../Exceptions.h"
#include "../Debug/Debug.h"
#include "../States/State.h"
#include "../Attack/BaseAttack.h"

class State;
class BaseAttack;

enum class UnitType {
    SOLDIER,
    ROGUE,
    BERSERKER
};

class Unit {
    protected:
        std::string name;
        State *state;
        BaseAttack *baseAttack;
        UnitType type;
        
        Unit(const std::string& name, State *state, BaseAttack *bAttack, UnitType type);
    public:
        virtual ~Unit();
        
        bool isAlive();
        void esureIsAlive();
        
        const std::string& getName() const;
        const State& getState() const;
        
        int getDamage() const;
        UnitType getType() const;
        
        void addHitPoints(int hp);
        void takeDamage(int dmg);
        
        void attack(Unit& enemy);
        void counterAttack(Unit& enemy);
};

std::ostream& operator<<(std::ostream& out, const Unit& unit);
std::ostream& operator<<(std::ostream& out, const UnitType& type);

#endif // UNIT_H
