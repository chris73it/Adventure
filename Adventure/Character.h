#pragma once
#include <string>

class Character
{
protected:
	std::string m_name;
	int m_health;
	int m_strength;

public:
	Character(std::string _name, int _health, int _strength)
		: m_name{ _name }, m_health {_health}, m_strength{ _strength }
	{
	}

	~Character() {}

	virtual void attack(Character* ) =0;
	virtual int hit(int strength) = 0;
	std::string getName()
	{
		return m_name;
	}
	int getHealth()
	{
		return m_health;
	}
};