#include <iostream>
#include <vector>
#include "Character.h"
#include "Avatar.h"
#include "Vampire.h"
#include "Werewolf.h"
#include "Zombie.h"

Avatar hero{"Chris", 100, 25};

std::vector<Character*> monsters = {
	new Vampire{"Dracula", 15, 5},
	new Werewolf{"Bartok", 10, 10},
	new Zombie{"Mr. Smith", 5, 20}
};

int main()
{
	//1. Print on the screen how the avatar is doing.
	std::cout << hero.getName() << " has " << hero.getHealth() << " energy left." << std::endl;

	//2. Print on the screen what monsters are left, their energy and the hero's energy as well
	if (monsters.size() == 1)
		std::cout << "There is one single monster still alive: ";
	else
		std::cout << "There are " << monsters.size() << " monsters still alive: ";
	for (size_t index = 0; index < monsters.size() -1; index++)
	{
		std::cout << monsters[index]->getName()
			<< " (energy: " << monsters[index]->getHealth() << "), ";
	}
	std::cout << monsters[monsters.size()-1]->getName()
		<< " (energy: " << monsters[monsters.size() - 1]->getHealth() << ")."
		<< std::endl;

	//3. Ask the player what weapons s/he wants to use

	//4. Check if the current monster is dead, in which case move to the next monster

	//5. If the current monster is NOT dead, have it attack the avatar

	//6. If the avatar is dead, then it is GAME OVER

	//7. If there are no more monsters (they are all dead) then VICTORY!

	return 0;
}