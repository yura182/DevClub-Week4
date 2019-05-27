#ifndef WIZARD_H
#define WIZARD_H

#include "../../Helpers/Debug.h"
#include "../SpellCaster.h"
#include "../../States/State.h"

class Wizard : public SpellCaster {
    public:
        Wizard(const std::string& name, int mana, int hp=intVal(Health::WIZARD), int dmg=intVal(Damage::WIZARD));
        ~Wizard();
};

#endif // WIZARD_H
