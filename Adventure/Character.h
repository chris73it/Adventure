#pragma once
#include "Avatar.h"

class Character
{
protected:
	int m_health;
	int m_strength;
public:
	Character(int _health, int _strength)
		: m_health{ _health }, m_strength{_strength}
	{
	}

	~Character() {}

	virtual void attack(Character* ) = 0;
	virtual int hit(int strength) =0;
};