#include <string>
#include <iostream>
#include <vector>
#include "Character.h"
#include "Avatar.h"
#include "Vampire.h"
#include "Werewolf.h"
#include "Zombie.h"

Avatar hero{"Chris", 100, 12};

std::vector<Character*> monsters = {
	new Vampire{"Dracula", 15, 20},
	new Werewolf{"Bartok", 18, 15},
	new Zombie{"Mr. Smith",24, 10}
};

std::string monsterEnergy(size_t index)
{
	return std::string(" (energy: ") + std::to_string(monsters[index]->getHealth()) + std::string(")");
}

std::string monsterBanner(size_t monsterSize)
{
	if (monsterSize == 1)
		return std::string("There is one single monster still alive: ");
	else
		return std::string("There are ") + std::to_string(monsterSize) + std::string(" monsters still alive: ");
}

char* getAlphabet()
{
	char* alphabet = new char[26];
	for (size_t letter = 'a'; letter <= 'z'; letter++)
	{
		alphabet[letter - 'a'] = (int)letter;
	}
	return alphabet;
}

int main(int argc, char** argv)
{
	char* alphabet = getAlphabet();

	//1. Print on the screen how the avatar is doing.
	std::cout << hero.getName() << " has " << hero.getHealth() << " energy left." << std::endl << std::endl;

	//2. Print on the screen what monsters are left, their energy and the hero's energy as well
	auto monsterSize = monsters.size();
	std::cout << monsterBanner(monsterSize);
	std::cout << std::endl;
	size_t index;
	for (index = 0; index < monsterSize; index++)
	{
		std::cout << "  [" << alphabet[index] << "] "
			<< monsters[index]->getName()
			<< "\t" << monsterEnergy(index) << std::endl;
	}
	std::cout << std::endl;

	//3. Ask the player what weapons s/he wants to use
	int choice;
	std::cout << "What monster do you want to attack? ";
	std::cin >> choice;

	//4. Check if the current monster is dead, in which case move to the next monster

	//5. If the current monster is NOT dead, have it attack the avatar

	//6. If the avatar is dead, then it is GAME OVER

	//7. If there are no more monsters (they are all dead) then VICTORY!

	return 0;
}