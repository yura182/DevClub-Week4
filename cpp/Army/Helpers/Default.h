#ifndef DEFAULT_H
#define DEFAULT_H

enum class Health {
    SOLDIER = 100,
    ROGUE = 90,
    BERSERKER = 85,
    VAMPIRE = 75,
    WEREWOLF = 65,
    WOLF = 130,
    
    WIZARD = 50
};

enum class Damage {
    SOLDIER = 30,
    ROGUE = 35,
    BERSERKER = 35,
    VAMPIRE = 30,
    WEREWOLF = 25,
    WOLF = 50,
    
    WIZARD = 15
};

enum class Mana {
    WIZARD = 50
};

enum class SpellDmg {
    FIREBALL = 20
};

enum class SpellCost {
    FIREBALL = 10
};

template <typename Enumeration>
auto intVal(Enumeration const value)
    -> typename std::underlying_type<Enumeration>::type
{
    return static_cast<typename std::underlying_type<Enumeration>::type>(value);
};

#endif // DEFAULT_H
