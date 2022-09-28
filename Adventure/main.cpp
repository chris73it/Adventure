#include <iostream>
#include <vector>
#include "Character.h"
#include "Avatar.h"
#include "Vampire.h"
#include "Werewolf.h"
#include "Zombie.h"

Avatar hero{100, 25};

std::vector<Character*> monsters = {
	new Vampire{15, 5},
	new Werewolf{10, 10},
	new Zombie{5, 20}
};

int main()
{
	//1. Initialize data structures

	//2. Print on the screen what monsters are left, their energy and the hero's energy as well

	//3. Ask the player what weapons s/he wants to use

	//4. Check if the current monster is dead, in which case move to the next monster

	//5. If the current monster is NOT dead, have it attack the avatar

	//6. If the avatar is dead, then it is GAME OVER

	//7. If there are no more monsters (they are all dead) then VICTORY!

	return 0;
}