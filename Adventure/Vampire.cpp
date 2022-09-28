#include "Vampire.h"

Vampire::Vampire(int _health, int _strength)
    : Character{ _health, _strength }
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