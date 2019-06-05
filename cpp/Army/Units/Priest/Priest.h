#ifndef PRIEST_H
#define PRIEST_H

#include "../../Helpers/Debug.h"
#include "../SpellCaster.h"
#include "../../States/State.h"
#include "../../Cast/PriestCast/PriestCast.h"
#include "../../Attacks/PriestAttack/PriestAttack.h"

class Priest : public SpellCaster {
    public:
        Priest(const std::string& name, int mana=intVal(Mana::PRIEST), int hp=intVal(Health::PRIEST), int dmg=intVal(Damage::PRIEST));
        ~Priest();
};

#endif // PRIEST_H
