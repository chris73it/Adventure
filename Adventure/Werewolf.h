#pragma once
#include "Character.h"

class Werewolf :
    public Character
{
public:
    Werewolf(int _health, int _strength);
    void attack(Character* avatar) override;
    int hit(int _strength) override;
};

