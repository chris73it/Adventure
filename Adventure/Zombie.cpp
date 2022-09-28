#include "Zombie.h"

Zombie::Zombie(int _health, int _strength)
    : Character{ _health, _strength }
{
}

void Zombie::attack(Character* avatar)
{

}

int Zombie::hit(int _strength)
{
    return 0;
}