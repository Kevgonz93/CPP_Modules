#include "zombie.hpp"

Zombie *zombieHorde(int N, std::string name);

int main()
{
	const int N = 5;
	std::string name = "Zombie";

	Zombie* horde = zombieHorde(N, name);
	if (horde == NULL)
		return 1;

	delete[] horde;
	return 0;
}
