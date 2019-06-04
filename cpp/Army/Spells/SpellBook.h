#ifndef SPELLBOOK_H
#define SPELLBOOK_H

#include <map>
#include "../Helpers/Debug.h"
#include "Spell.h"
#include "../Helpers/Exceptions.h"
#include "Fireball/Fireball.h"

class SpellBook {
    private:
        std::map<std::string, Spell*> book;
    public:
        SpellBook();
        ~SpellBook();
        
        const std::map<std::string, Spell*>& getBook() const;
        
        void insertSpell(Spell* spell);
        bool haveSpell(const std::string& name) const;
        Spell& getSpell(const std::string& name) const;
};

std::ostream& operator<<(std::ostream& out, const SpellBook& book);

#endif // SPELLBOOK_H
