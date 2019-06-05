#ifndef SPELLCASTER_H
#define SPELLCASTER_H

#include "../Helpers/Debug.h"
#include "Unit.h"
#include "../States/SpellCasterState.h"
#include "../Spells/Spell.h"
#include "../Spells/SpellBook.h"
#include "../Cast/Cast.h"


class SpellCaster : public Unit {
    protected:
        SpellBook *spellBook;
        SpellCasterState *scState;
        Cast *cast;
    public:
        SpellCaster(const std::string& name, State *state, SpellCasterState *scState, BaseAttack *bAttack, SpellBook *spellBook, UnitType type, UnitType stateType, Cast *cast);
        virtual ~SpellCaster();
        
        SpellCasterState& getScState() const;
        int getMana() const;
        SpellBook& getSpellBook() const;
        Spell& getSpell(const std::string name) const;
        
        void addMana(int mana);
        
        void castAction(Unit& unit, Spell& spell);
        virtual void castAction(Spell& spell);
        
        bool haveMana() const;
        bool haveEnoughMana(Spell& spell) const;
        
        void showSpellBook() const;
        virtual void showSpecial() const;
};

std::ostream& operator<<(std::ostream& out, const SpellCaster& sCaster);

#endif // SPELLCASTER_H
