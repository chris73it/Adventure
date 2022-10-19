#include <string>
#include <iostream>
#include <vector>
#include "Character.h"
#include "Avatar.h"
#include "Vampire.h"
#include "Werewolf.h"
#include "Zombie.h"

Avatar avatar{"Chris", 81, 12};
char* alphabet;
size_t monstersLeft;

std::vector<Character*> monsters = {
	new Vampire{"Dracula", 10, 20},
	new Werewolf{"Bartok", 18, 15},
	new Zombie{"Mr. Smith",30, 10}
};

std::string monsterEnergy(size_t index)
{
	return std::string(" (health: ") + std::to_string(monsters[index]->getHealth()) + std::string(")");
}

std::string monsterBanner(size_t monstersLeft)
{
	if (monstersLeft == 1)
		return std::string("There is one single monster still alive: ");
	else
		return std::string("There are ") + std::to_string(monstersLeft) + std::string(" monsters still alive: ");
}

static char* getAlphabet()
{
	static char* alphabet = nullptr;
	if (!alphabet)
	{
		alphabet = new char[26];
		//std::cerr << "alphabet pointer is not null." << std::endl;
	}
	for (size_t letter = 'a'; letter <= 'z'; letter++)
	{
		alphabet[letter - 'a'] = (int)letter;
	}
	return alphabet;
}

void pleasePressAOnce()
{
	std::cerr << "Please, press 'a' once to attack " << monsters[0]->getName() << "." << std::endl;
}

void pleaseEnterSingleLetter()
{
	std::cerr << "Please, enter a single letter between 'a' and '" << alphabet[monstersLeft - 1] << "'. " << std::endl;
}

int main(int argc, char** argv)
{
	alphabet = getAlphabet();

	//2. Ask player wha monster s/he wants to attack.
	std::string choice;
	while (true)
	{
		std::cout << std::endl << "################################################################"
			<< std::endl << std::endl;
		
		monstersLeft = monsters.size();

		if (monstersLeft == 0 || avatar.getHealth() <= 0)
		{
			break;
		}

		//1. Print on the screen how the avatar is doing.
		std::cout << avatar.getName() << " has " << avatar.getHealth() << " health left." << std::endl;

		std::cout << std::endl;

		//3. Print on the screen what monsters are left, their health and the hero's health as well
		std::cout << monsterBanner(monstersLeft) << std::endl;
		for (size_t index = 0; index < monstersLeft; index++)
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
			if (monstersLeft == 1)
			{
				pleasePressAOnce();
			}
			else
			{
				pleaseEnterSingleLetter();
			}
			continue;
		}

		if (choice[0] >= 'A' && choice[0] <= 'Z')
		{
			//Convert A .. Z to a .. z
			int asciiChoiceIndex = (int)choice[0] + ('a' - 'A');
			choice = alphabet[asciiChoiceIndex - 'a'];
		}

		if (monstersLeft == 1 && choice[0] != 'a')
		{
			pleasePressAOnce();
			continue;
		}

		if (choice[0] < 'a' || choice[0] > alphabet[monstersLeft - 1])
		{
			pleaseEnterSingleLetter();
			continue;
		}

		//6. Attack the chosen monster and check its health.
		size_t currentMonsterIndex = choice[0] - 'a';
		Character* currentMonster = monsters[currentMonsterIndex];
		int avatarAttack = avatar.attack(currentMonster);
		if (currentMonster->getHealth() <= 0)
		{
			std::cout << avatar.getName() << " killed " << currentMonster->getName() << "." << std::endl;
			monsters.erase(monsters.begin() + currentMonsterIndex);
			monstersLeft--;
		}
		else
		{
			std::cout << avatar.getName() << " attacked (strength: " << avatarAttack << ") "
				<< currentMonster->getName() << "." << std::endl;
		}

		//7. Since at least one monster is still alive, make the monster attack the avatar.
		for (size_t index = 0; index < monstersLeft; index++)
		{
			int monsterAttack = monsters[index]->attack(&avatar);
			if (avatar.getHealth() <= 0)
			{
				std::cout << monsters[index]->getName() << " killed " << avatar.getName() << "." << std::endl;
				break;
			}
			else
			{
				std::cout << monsters[index]->getName() << " attacked (strength: " << monsterAttack << ") "
					<< avatar.getName() << "." << std::endl;
			}
		}
	}

	//8. Game is over: did the avatar win or did the monsters kill the hero?
	if (avatar.getHealth() <= 0)
	{
		std::cout << "GAME OVER" << std::endl;
	}
	else
	{
		std::cout << "All monsters are dead!" << std::endl;
	}

	return 0;
}