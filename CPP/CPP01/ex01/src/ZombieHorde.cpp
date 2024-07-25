#include "../inc/Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie	*zombieHorde = new Zombie[N];
	for (int i = -1; ++i < N;)
		zombieHorde[i].setName(name);
	return (zombieHorde);
}