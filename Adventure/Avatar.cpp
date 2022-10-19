#include "Avatar.h"

Avatar::Avatar(std::string _name, int _health, int _strength)
    : Character{ _name, _health, _strength }
{
}

int Avatar::attack(Character* _monster)
{
    int monsterHealthAfterAttack = hit(_monster);
    _monster->setHealth(monsterHealthAfterAttack);
    return m_attackStrength;
}

int Avatar::hit(Character* _monster)
{
    int monsterHealth = _monster->getHealth();
    monsterHealth -= m_attackStrength;
    return monsterHealth;
}