#include "../inc/Zombie.hpp"

int	main()
{
	Zombie *zombie;
	Zombie *zombies;

	zombie = newZombie("test");
	randomChump("essaie");
	zombies = zombieHorde(5, "test");
	delete[] zombies;
	delete zombie;
	return 0;
}