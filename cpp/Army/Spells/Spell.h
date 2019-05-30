#ifndef SPELL_H
#define SPELL_H

#include "../Helpers/Debug.h"

class Spell {
    protected:
        std::string name;
        int manaCost;
        int damage;
    public:
        Spell(const std::string& name, int manaCost, int damage);
        ~Spell();
        
        const std::string& getName() const;
        int getManaCost() const;
        int getDamage() const;
};

#endif // SPELL_H
