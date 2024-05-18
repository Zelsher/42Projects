#include "../inc/HumanA.hpp"
#include "../inc/HumanB.hpp"

int	main()
{
{
	Weapon club = Weapon("crude spiked club");
	HumanA bob("Bob", club);
	bob.ATTACK();
	club.SET_Type("some other type of club");
	bob.ATTACK();
}
{
	Weapon club = Weapon("crude spiked club");
	HumanB jim("Jim");
	jim.SET_Weapon(club);
	jim.ATTACK();
	club.SET_Type("some other type of club");
	jim.ATTACK();
}
}