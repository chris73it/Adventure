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

	//3. Ask the player what monster s/he wants to attack
	bool repeatInput = true;
	std::string choice;
	while (repeatInput)
	{
		std::cout << std::endl;

		std::cout << "What monster do you want to attack? ";
		std::cin >> choice;

		//4. Make sure choice is sound: for instance, if there are only 3 monsters, the player
		//   should only be allowed to type a b or c, and not d ... z.
		if (choice.length() != 1)
		{
			std::cerr << "Please, enter a single letter between a and " << alphabet[monsterSize - 1] << std::endl;
			continue;
		}
		
		//Convert A .. Z to a .. z
		if (choice[0] >= 'A' && choice[0] <= 'Z')
		{
			int asciiChoiceIndex = (int)choice[0] + ('a' - 'A');
			choice = alphabet[asciiChoiceIndex - 'a'];
		}

		if (choice[0] < 'a' || choice[0] > alphabet[monsterSize - 1])
		{
			std::cerr << "Please, enter a letter between a and " << alphabet[monsterSize - 1] << std::endl;
			continue;
		}

		//Input is correct, so no need to keep looping
		repeatInput = false;
	}

	//5. If the current monster is NOT dead, have it attack the avatar

	//6. If the avatar is dead, then it is GAME OVER

	//7. If there are no more monsters (they are all dead) then VICTORY!

	return 0;
}