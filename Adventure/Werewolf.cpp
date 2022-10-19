#include "Werewolf.h"

Werewolf::Werewolf(std::string _name, int _health, int _strength)
    : Character{ _name, _health, _strength }
{
}

int Werewolf::attack(Character* _avatar)
{
    int avatarHealthAfterAttack = hit(_avatar);
    _avatar->setHealth(avatarHealthAfterAttack);
    return m_attackStrength;
}

int Werewolf::hit(Character* _avatar)
{
    int avatarHealth = _avatar->getHealth();
    avatarHealth -= m_attackStrength;
    return avatarHealth;
}