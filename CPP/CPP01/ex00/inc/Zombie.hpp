#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

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
		~Zombie()
		{
			cout << "Deconstructeur sur " << name << endl;
		}
};

Zombie* newZombie(string name);
void randomChump(string name);

#endif
