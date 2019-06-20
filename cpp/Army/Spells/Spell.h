#ifndef SPELL_H
#define SPELL_H

#include "../Helpers/Debug.h"
#include "../Helpers/Default.h"
#include "../Units/Unit.h"

enum class SpellType {
    DMG,
    HEAL,
    SUMMON
};

class Spell {
    protected:
        std::string name;
        int manaCost;
        int damage;
        SpellType type;
    public:
        Spell(const std::string& name, int manaCost, int damage, SpellType type);
        virtual ~Spell();
        
        const std::string& getName() const;
        int getManaCost() const;
        int getDamage() const;
        SpellType getType() const;
        virtual Unit* summon(int x, int y) const;
};

std::ostream& operator<<(std::ostream& out, const Spell& spell);

#endif // SPELL_H
