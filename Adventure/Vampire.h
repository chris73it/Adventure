#pragma once
#include "Character.h"

class Vampire : public Character
{
public:
    Vampire(std::string _name, int _health, int _strength);
    int attack(Character* _avatar) override;
    int hit(Character* _avatar) override;
};

