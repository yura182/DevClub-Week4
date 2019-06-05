#ifndef WIZARDCAST_H
#define WIZARDCAST_H

#include "../Cast.h"

class WizardCast : public Cast {
    public:
        WizardCast();
        ~WizardCast();
        
        void action(Unit& unit, Spell& spell);
};

#endif // WIZARDCAST_H
