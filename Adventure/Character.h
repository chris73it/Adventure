#pragma once
#include <string>

class Character
{
protected:
	std::string m_name;
	int m_health;
	int m_attackStrength;

public:
	Character(std::string _name, int _health, int _strength)
		: m_name{ _name }, m_health {_health}, m_attackStrength{ _strength }
	{
	}

	~Character() {}

	virtual void attack(Character* ) =0;
	virtual int hit(Character* _character) =0;

	std::string getName()
	{
		return m_name;
	}

	int getHealth()
	{
		return m_health;
	}
	void setHealth(int _newCharacterHealth)
	{
		m_health = _newCharacterHealth;
	}
};