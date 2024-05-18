#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA
{
	private:
		string	name;
		Weapon&	weapon;
	public:
		HumanA(const std::string& new_name, Weapon& new_weapon) : name(new_name), weapon(new_weapon) 
		{
    	}
		~HumanA()
		{
			
		}
		void	ATTACK()
		{
			cout << name << " attacks with their " << weapon.GET_Type() << endl;
		}
};

#endif