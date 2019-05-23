#ifndef SPELLCASTER_H
#define SPELLCASTER_H

#include "../Debug/Debug.h"
#include "Unit.h"
#include "../States/SpellCasterState.h"

class SpellCaster : public Unit {
    protected:
        SpellCasterState *scState;
    
    public:
        SpellCaster(const std::string& name, State *state, SpellCasterState *scState, BaseAttack *bAttack, UnitType type);
        ~SpellCaster();
        
        SpellCasterState& getScState() const;
        int getMana() const;
        
        void addMana(int mana);
};

std::ostream& operator<<(std::ostream& out, const SpellCaster& sCaster);

#endif // SPELLCASTER_H
