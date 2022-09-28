#include "Avatar.h"

Avatar::Avatar(std::string _name, int _health, int _strength)
    : Character{ _name, _health, _strength }
{
}

void Avatar::attack(Character* monster)
{
}

int Avatar::hit(int strength)
{
    return 0;
}