#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void	Remplace_string(string &content, string s1, string s2)
{
	size_t	pos = 0;

	while ((pos = content.find(s1, pos)) != string::npos)
	{
		content.replace(pos, s1.length(), s2);
		pos += s2.length();
	}
}

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		cerr << "Wrong number of arguments" << endl;
		return (1);
	}
	string	buffer;
	string	file_name(av[1]);

	file_name.append(".replace");
	if (ac != 4)
		return (1);

	ifstream	read_file(av[1]);
	ofstream	write_file(file_name);
	if (!read_file.is_open() || !write_file.is_open())
	{
		cerr << "File issue" << endl;
		return (1);
	}
	string		content((istreambuf_iterator<char>(read_file) ), (istreambuf_iterator<char>()));
	Remplace_string(content, av[2], av[3]);
	//write_file << content;
}
