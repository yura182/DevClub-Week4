#ifndef SPELLCASTERSTATE_H
#define SPELLCASTERSTATE_H

#include "../Helpers/Debug.h"

class SpellCasterState {
    private:
        int mana;
        int manaLimit;
    public:
        SpellCasterState(int mana);
        ~SpellCasterState();
        
        int getMana() const;
        int getManaLimit() const;
        
        void addMana(int mana);
        void reduceMana(int mana);
};

std::ostream& operator<<(std::ostream& out, const SpellCasterState& scState);

#endif // SPELLCASTERSTATE_H
