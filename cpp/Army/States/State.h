#ifndef STATE_H
#define STATE_H

#include <iostream>
#include "../Helpers/Debug.h"

class State {
    private:
        int damage;
        int hitPoints;
        int hitPointsLimit;
    public:
        State(int hp, int dmg);
        ~State();
        
        int getDamage() const;
        int getHitPoints() const;
        int getHitPointsLimit() const;
        
        void addHitPoints(int hp);
        void takeDamage(int hp);
};

std::ostream& operator<<(std::ostream& out, const State& state);

#endif // STATE_H
