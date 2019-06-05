#ifndef DEFAULT_H
#define DEFAULT_H

enum class Health {
    SOLDIER = 100,
    ROGUE = 90,
    BERSERKER = 85,
    VAMPIRE = 75,
    WEREWOLF = 65,
    WOLF = 130,
    DEMON = 35,
    
    WIZARD = 50,
    HEALER = 55,
    PRIEST = 49,
    WARLOCK = 44
};

enum class Damage {
    SOLDIER = 40,
    ROGUE = 35,
    BERSERKER = 38,
    VAMPIRE = 30,
    WEREWOLF = 31,
    WOLF = 50,
    DEMON = 15,
    
    WIZARD = 18,
    HEALER = 20,
    PRIEST = 22,
    WARLOCK = 18
};

enum class Mana {
    WIZARD = 50,
    HEALER = 65,
    PRIEST = 70,
    WARLOCK = 60
};

enum class SpellDmg {
    FIREBALL = 20,
    MAGICARROW = 15,
    CURE = 25
};

enum class SpellCost {
    FIREBALL = 10,
    MAGICARROW = 7,
    CURE = 9,
    SUMMONDEMON = 10
};

template <typename Enumeration>
auto intVal(Enumeration const value)
    -> typename std::underlying_type<Enumeration>::type
{
    return static_cast<typename std::underlying_type<Enumeration>::type>(value);
};

#endif // DEFAULT_H
