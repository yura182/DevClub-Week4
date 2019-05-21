#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include "../Exceptions.h"
#include "../Debug.h"
#include "../States/State.h"
#include "../Attack/BaseAttack.h"

class State;
class BaseAttack;

class Unit {
    protected:
        std::string name;
        State *state;
        BaseAttack *baseAttack;
    public:
        Unit(const std::string& name, int hp, int dmg);
        ~Unit();
        
        bool isAlive();
        void esureIsAlive();
        
        const std::string& getName() const;
        const State& getState() const;
        
        int getDamage() const;
        
        void addHitPoints(int hp);
        void takeDamage(int dmg);
        
        void attack(Unit& enemy);
        void counterAttack(Unit& enemy);
};

std::ostream& operator<<(std::ostream& out, const Unit& unit);

#endif // UNIT_H
