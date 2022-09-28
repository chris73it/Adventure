#include "Zombie.h"

Zombie::Zombie(std::string _name, int _health, int _strength)
    : Character{ _name, _health, _strength }
{
}

void Zombie::attack(Character* avatar)
{

}

int Zombie::hit(int _strength)
{
    return 0;
}