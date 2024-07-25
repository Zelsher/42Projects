#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class Zombie 
{
	private :
		string	name;

	public :
		void	announce()
		{

			cout << name << ": BraiiiiiiinnnzzzZ..." << endl;
		}

		Zombie(string new_name)
		{
			name = new_name;
			announce();
		}
		Zombie()
		{
		}
		~Zombie()
		{
			cout << "Deconstructeur sur " << name << endl;
		}

		void	setName(string new_name)
		{
			name = new_name;
			announce();
		}
};

Zombie* newZombie(string name);
void randomChump(string name);
Zombie* zombieHorde(int N, std::string name);

#endif
