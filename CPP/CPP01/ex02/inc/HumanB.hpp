#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
	private:
		string	name;
		Weapon	*weapon;
	public:
		HumanB(string new_name)
		{
			name = new_name;
			weapon = nullptr;
		}
		~HumanB()
		{
			
		}
		void	ATTACK()
		{
			cout << name << " attacks with their " << weapon->GET_Type() << endl;
		}
		void	SET_Weapon(Weapon new_weapon)
		{
			weapon = &new_weapon;
		}
};

#endif
