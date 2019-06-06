#ifndef STATE_H
#define STATE_H

#include <iostream>
#include "../Helpers/Debug.h"
#include "../Helpers/Randomizer.h"
#include "../Units/Unit.h"

class Unit;

class State {
    private:
        int damage;
        int hitPoints;
        int hitPointsLimit;
    public:
        State(int hp, int dmg, int hpLim=0);
        virtual ~State();
        
        int getDamage() const;
        int getHitPoints() const;
        int getHitPointsLimit() const;
        
        void setDamage(int dmg);
        void setHitPoints(int hp);
        void setHitPointsLimit(int hpLim);
        
        void addHitPoints(int hp);
        void takeDamage(int hp);
        virtual void takeMagicDamage(int dmg);
        
        virtual void transform(Unit& unit);
};

std::ostream& operator<<(std::ostream& out, const State& state);

#endif // STATE_H
