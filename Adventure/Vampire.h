#pragma once
#include "Character.h"

class Vampire : public Character
{
public:
    Vampire(int _health, int _strength);
    void attack(Character* avatar) override;
    int hit(int _strength) override;
};

