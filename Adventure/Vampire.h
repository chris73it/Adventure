#pragma once
#include "Character.h"

class Vampire : public Character
{
public:
    Vampire(std::string _name, int _health, int _strength);
    void attack(Character* avatar) override;
    int hit(int _strength) override;
};

