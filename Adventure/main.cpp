#include <string>
#include <iostream>
#include <vector>
#include "Character.h"
#include "Avatar.h"
#include "Vampire.h"
#include "Werewolf.h"
#include "Zombie.h"

Avatar avatar{"Chris", 100, 12};

std::vector<Character*> monsters = {
	new Vampire{"Dracula", 15, 20},
	new Werewolf{"Bartok", 18, 15},
	new Zombie{"Mr. Smith",24, 10}
};

std::string monsterEnergy(size_t index)
{
	return std::string(" (health: ") + std::to_string(monsters[index]->getHealth()) + std::string(")");
}

std::string monsterBanner(size_t monsterSize)
{
	if (monsterSize == 1)
		return std::string("There is one single monster still alive: ");
	else
		return std::string("There are ") + std::to_string(monsterSize) + std::string(" monsters still alive: ");
}

static char* getAlphabet()
{
	static char* alphabet = nullptr;
	if (!alphabet)
	{
		alphabet = new char[26];
		std::cout << "alphabet pointer is not null." << std::endl;
	}
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
	std::cout << avatar.getName() << " has " << avatar.getHealth() << " health left." << std::endl << std::endl;

	//2. Ask player wha monster s/he wants to attack.
	std::string choice;
	bool repeatInput = true;
	while (repeatInput)
	{
		std::cout << std::endl;

		//3. Print on the screen what monsters are left, their health and the hero's health as well
		auto monsterSize = monsters.size();
		std::cout << monsterBanner(monsterSize) << std::endl;
		for (size_t index = 0; index < monsterSize; index++)
		{
			std::cout << "  [" << alphabet[index] << "] "
				<< monsters[index]->getName()
				<< "\t" << monsterEnergy(index) << std::endl;
		}
		std::cout << std::endl;

		//4. Ask the player what monster s/he wants to attack
		std::cout << "What monster do you want to attack? ";
		std::cin >> choice;

		//5. Make sure choice is sound: for instance, if there are only 3 monsters, the player
		//   should only be allowed to type a b or c, and not d ... z, or random characters like semicolon, or digits.
		if (choice.length() != 1)
		{
			if (monsterSize == 1)
			{
				std::cerr << "Please, press 'a' once to attack " << monsters[0]->getName() << "." << std::endl;
			}
			else
			{
				std::cerr << "Please, enter a single letter between 'a' and '" << alphabet[monsterSize - 1] << "'. " << std::endl;
			}
			continue;
		}

		if (choice[0] >= 'A' && choice[0] <= 'Z')
		{
			//Convert A .. Z to a .. z
			int asciiChoiceIndex = (int)choice[0] + ('a' - 'A');
			choice = alphabet[asciiChoiceIndex - 'a'];
		}

		if (monsterSize == 1 && choice[0] != 'a')
		{
			std::cerr << "Please, press a to attack " << monsters[0]->getName() << "." << std::endl;
			continue;
		}

		if (choice[0] < 'a' || choice[0] > alphabet[monsterSize - 1])
		{
			std::cerr << "Please, enter a letter between a and " << alphabet[monsterSize - 1] << std::endl;
			continue;
		}

		//6. Attack the chosen monster and check its health.
		size_t currentMonsterIndex = choice[0] - 'a';
		Character* currentMonster = monsters[currentMonsterIndex];
		avatar.attack(currentMonster);
		if (currentMonster->getHealth() <= 0)
		{
			std::cout << avatar.getName() << " killed " << currentMonster->getName() << "." << std::endl;
			monsters.erase(monsters.begin() + currentMonsterIndex);
			continue;
		}
		else
		{
			std::cout << avatar.getName() << " attacked " << currentMonster->getName()
				<< " (health: " << currentMonster->getHealth() << ".)" << std::endl;
		}

		//7. Since the monster is still alive, make the monster attack the avatar.
		// ...
		
		//Input is correct, so no need to keep looping
		//repeatInput = false;
	}

	//5. If the current monster is NOT dead, have it attack the avatar

	//6. If the avatar is dead, then it is GAME OVER

	//7. If there are no more monsters (they are all dead) then VICTORY!

	return 0;
}