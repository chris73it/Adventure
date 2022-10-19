#pragma once
#include "Character.h"

class Werewolf :
    public Character
{
public:
    Werewolf(std::string _name, int _health, int _strength);
    int attack(Character* avatar) override;
    int hit(Character* _character) override;
};

