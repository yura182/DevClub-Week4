#ifndef SPELL_H
#define SPELL_H

#include "../Helpers/Debug.h"
#include "../Helpers/Default.h"

class Spell {
    protected:
        std::string name;
        int manaCost;
        int damage;
    public:
        Spell(const std::string& name, int manaCost, int damage);
        virtual ~Spell();
        
        const std::string& getName() const;
        int getManaCost() const;
        int getDamage() const;
};

std::ostream& operator<<(std::ostream& out, const Spell& spell);

#endif // SPELL_H
