#pragma once
#include "Character.h"

class Zombie :
    public Character
{
public:
    Zombie(std::string _name, int _health, int _strength);
    void attack(Character* avatar) override;
    int hit(int _strength) override;
};

