#include "zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	if (N <= 0)
		return NULL;

	Zombie* horde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		std::string indexedName = name + "_" + std::to_string(i + 1);
		horde[i].setName(indexedName);
		horde[i].announce();
	}

	return horde;
}
