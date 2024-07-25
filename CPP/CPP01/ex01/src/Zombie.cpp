#include "../inc/Zombie.hpp"

Zombie* newZombie(string name)
{
	Zombie	*new_zombie = new Zombie(name);
	return (new_zombie);
}