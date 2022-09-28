#include "Werewolf.h"

Werewolf::Werewolf(std::string _name, int _health, int _strength)
    : Character{ _name, _health, _strength }
{
}

void Werewolf::attack(Character* avatar)
{

}

int Werewolf::hit(int _strength)
{
    return 0;
}