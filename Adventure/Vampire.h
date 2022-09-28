#pragma once
#include "Character.h"

class Vampire : public Character
{
public:
    Vampire(int _health, int _strength)
        : Character{ _health, _strength }
    {
    }

    void attack(Character* avatar) override
    {
        avatar->hit(m_strength);
    }
    int hit(int _strength) override
    {
        m_health -= _strength;
        return m_health;
    }

};

