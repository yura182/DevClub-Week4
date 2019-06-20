#ifndef NECROMANCER_H
#define NECROMANCER_H

#define HP_LIMIT_COEFF_NECR 1.5

#include "../../Helpers/Debug.h"
#include "../SpellCaster.h"
#include "../../States/State.h"
#include "../../Cast/Cast.h"
#include "../../Interfaces/Observer.h"

class Necromancer : public SpellCaster, public Observer {
    public:
        Necromancer(const std::string& name, int x, int y, int mana=intVal(Mana::NECROMANCER), int hp=intVal(Health::NECROMANCER), int dmg=intVal(Damage::NECROMANCER));
        ~Necromancer();
        
        virtual void update(int hp);
        
        virtual void attack(Unit& enemy);
        virtual void counterAttack(Unit& enemy);
};

#endif // NECROMANCER_H
