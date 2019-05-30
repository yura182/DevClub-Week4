#ifndef SPELLCASTER_H
#define SPELLCASTER_H

#include "../Helpers/Debug.h"
#include "Unit.h"
#include "../States/SpellCasterState.h"
#include "../Spells/Spell.h"
#include "../Cast/Cast.h"


class SpellCaster : public Unit {
    protected:
        Spell *spell;
        SpellCasterState *scState;
        Cast *cast;
    public:
        SpellCaster(const std::string& name, State *state, SpellCasterState *scState, BaseAttack *bAttack, Spell *spell, UnitType type);
        ~SpellCaster();
        
        SpellCasterState& getScState() const;
        int getMana() const;
        Spell& getSpell() const;
        
        void addMana(int mana);
        
        void castAction(Unit& unit, Spell& spell);
        
        bool haveMana() const;
        bool haveEnoughMana(Spell& spell) const;
};

std::ostream& operator<<(std::ostream& out, const SpellCaster& sCaster);

#endif // SPELLCASTER_H
