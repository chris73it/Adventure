#include "Vampire.h"

Vampire::Vampire(std::string _name, int _health, int _strength)
    : Character{ _name, _health, _strength }
{
}

void Vampire::attack(Character* _avatar)
{
    _avatar->hit(m_strength);
}

int Vampire::hit(int _strength)
{
    m_health -= _strength;
    return m_health;
}