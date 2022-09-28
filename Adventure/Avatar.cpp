#include "Avatar.h"

Avatar::Avatar(int _health, int _strength)
    : Character{ _health, _strength }
{
}

void Avatar::attack(Character* monster)
{
}

int Avatar::hit(int strength)
{
    return 0;
}