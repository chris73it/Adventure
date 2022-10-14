#include "Vampire.h"

Vampire::Vampire(std::string _name, int _health, int _strength)
    : Character{ _name, _health, _strength }
{
}

void Vampire::attack(Character* _avatar)
{
    int avatarHealthAfterAttack = hit(_avatar);
    _avatar->setHealth(avatarHealthAfterAttack);
}

int Vampire::hit(Character* _avatar)
{
    int avatarHealth = _avatar->getHealth();
    avatarHealth -= m_attackStrength;
    return avatarHealth;
}