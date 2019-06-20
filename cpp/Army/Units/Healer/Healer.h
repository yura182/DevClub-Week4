#ifndef HEALER_H
#define HEALER_H

#include "../../Helpers/Debug.h"
#include "../SpellCaster.h"
#include "../../States/State.h"
#include "../../Cast/HealerCast/HealerCast.h"

class Healer : public SpellCaster {
    public:
        Healer(const std::string& name, int x, int y, int mana=intVal(Mana::HEALER), int hp=intVal(Health::HEALER), int dmg=intVal(Damage::HEALER));
        ~Healer();
};

#endif // HEALER_H
