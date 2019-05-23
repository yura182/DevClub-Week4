#ifndef WIZARD_H
#define WIZARD_H

#include "../../Debug/Debug.h"
#include "../SpellCaster.h"
#include "../../States/State.h"

class Wizard : public SpellCaster {
    public:
        Wizard(const std::string& name, int hp, int dmg, int mana);
        ~Wizard();
};

#endif // WIZARD_H
