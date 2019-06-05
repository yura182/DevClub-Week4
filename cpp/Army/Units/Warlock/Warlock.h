#ifndef WARLOCK_H
#define WARLOCK_H

#include <set>
#include "../../Helpers/Debug.h"
#include "../SpellCaster.h"
#include "../../States/State.h"
#include "../../Cast/Cast.h"

class Warlock : public SpellCaster {
    private:
        std::set<Unit*> demons;
    public:
        Warlock(const std::string& name, int mana=intVal(Mana::WARLOCK), int hp=intVal(Health::WARLOCK), int dmg=intVal(Damage::WARLOCK));
        ~Warlock();
        
        const std::set<Unit*>& getDemons() const;
        void castAction(Spell& spell);
        
        void showSpecial() const;
        void useAbility();
        
        void attack(Unit& enemy);
        void counterAttack(Unit& enemy);
};

std::ostream& operator<<(std::ostream& out, const std::set<Unit*>& demons);

#endif // WARLOCK_H
