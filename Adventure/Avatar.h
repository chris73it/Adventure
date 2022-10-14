#pragma once
#include "Character.h"

class Avatar :
    public Character
{
public:
    Avatar(std::string _name, int _health, int _strength);
    void attack(Character* _monster) override;
    int hit(Character* _monster) override;
};

