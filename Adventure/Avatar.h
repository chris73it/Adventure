#pragma once
#include "Character.h"

class Avatar :
    public Character
{
public:
    Avatar(int _health, int _strength)
        : Character{ _health, _strength }
    {
    }

    void attack(Character* monster) override
    {
        
    }

    int hit(int strength) override
    {

    }
};

