#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

using namespace std;

class Weapon 
{
	private:
		string	type;
	public:
		Weapon(string new_type)
		{
			type = new_type;
		}
		const string&	GET_Type()
		{
			return (type);
		}
		void	SET_Type(string new_type)
		{
			type = new_type;
		}
};

#endif
