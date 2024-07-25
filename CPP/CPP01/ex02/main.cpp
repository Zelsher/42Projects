#include <iostream>
#include <string>

using namespace std;

int	main()
{
	string	str("HI THIS IS BRAIN");
	string*	stringPTR = &str;
	string&	stringREF = str;

	cout << &str << endl;
	cout << stringPTR << endl;
	cout << &stringREF << endl;

	cout << str << endl;
	cout << *stringPTR << endl;
	cout << stringREF << endl;
}
