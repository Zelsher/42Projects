#include "PhoneBook.hpp"

void    CONSULT_Contact(PhoneBook &phone_book)
{
	string  input;
	int     i;

	phone_book.DISPLAY_Phone_book();
	cout << "Identifiant du contact (de 1 a 8): ";
	while (1)
	{
		getline(cin, input);
		stringstream(input) >> i;
		if (i == 0 or i > 8)
			cout << "Identifiant invalide, ressayez : ";
		else 
		{
			//cout << "Contact[" << i - 1 << "] : ";
			if (!phone_book.CONTACT_Exist(i - 1))
				cout << "Inexistant" << endl;
			else
				phone_book.DISPLAY_Contact(i - 1);
			break;
		}
	}
};

int main()
{
	PhoneBook	phone_book;
	string		input;

	while (1)
	{
		cout << "Entrez ADD pour ajouter un contact, SEARCH pour acceder a un contact, EXIT pour quitter: ";
		getline(cin, input);
		if (input == "ADD")
			phone_book.SET_Contact(phone_book.GET_Latest());
		else if (input == "SEARCH")
			CONSULT_Contact(phone_book);
		else if (input == "EXIT")
			break;
		else
			cout << "Invalid, veuillez ";
	}
	return 0;
}