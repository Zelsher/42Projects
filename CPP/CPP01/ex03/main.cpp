#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int	main(int ac, char **av)
{
	string	buffer;

	if (ac != 4)
		return (1);
	ofstream	file(av[1]);
	if (!file.is_open())
	{
		cout << "File issue" << endl;
		return (1);
	}
	while (getline(file, buffer))
	{
		cout << buffer << endl;
	}
}