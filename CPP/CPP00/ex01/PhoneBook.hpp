#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

class Contact 
{
	private:
		int		id;
		string	name;
		string	last_name;
		string	nickname;
		string	phone_nbr;
		string	darkest_secret;
	public:
		Contact()
		{
			id = 0;
		}
		int	EXIST()
		{
			if (id == 0)
				return 0;
			return 1;
		}

		void	DISPLAY()
		{   
    // Affichage des informations du contact
    		cout << setw(10) << right << id << " | "
			<< setw(10) << right << name.substr(0, 10) << " | "
              << setw(10) << right << last_name.substr(0, 10) << " | "
              << setw(10) << right << nickname.substr(0, 10) << endl;
		}

		void	PRINT()
		{
			cout << endl << "Id : " << id << endl
				 << "name : " << name << endl
				 << "last_name : " << last_name << endl
				 << "nickname : " << nickname << endl
				 << "phone_nbr : " << phone_nbr << endl
				 << "darkest_secret : " << darkest_secret << endl << endl;
		}

		void	SET_Info(int new_id)
		{
			id = new_id;
			while (name.empty())
			{
				cout << "Veuillez entrer un nom valide : ";
				getline(cin, name);
			}
			while (last_name.empty())
			{
				cout << "Veuillez entrer un last_name valide : ";
				getline(cin, last_name);
			}
			while (nickname.empty())
			{
				cout << "Veuillez entrer un nickname valide : ";
				getline(cin, nickname);
			}
			while (phone_nbr.empty())
			{
				cout << "Veuillez entrer un phone_nbr valide : ";
				getline(cin, phone_nbr);
			}
			while (darkest_secret.empty())
			{
				cout << "Veuillez entrer un secret valide : ";
				getline(cin, darkest_secret);
			}
			cout << "Contact ajouter avec succes !" << endl;
		}
};

class PhoneBook 
{
	private:
		Contact contact[8];
		int	latest;
	public:
		PhoneBook()
		{
			latest = 0;
		}

		int	CONTACT_Exist(int i)
		{
			return (contact[i].EXIST());
		}

		int	GET_Latest()
		{
			return (latest);
		}

		void	SET_Contact(int new_contact, int i)
		{
			if (!new_contact)
				return;
			contact[i].SET_Info(i + 1);
			if (i == 7)
				latest = 0;
			else
				latest = i + 1;
		}

		void	DISPLAY_Phone_book()
		{
			cout << endl << setw(10) << right << "ID" << " | "
      			<< setw(10) << right << "First Name" << " | "
				<< setw(10) << right << "Last Name" << " | "
            	<< setw(10) << right << "Nickname" << endl;
			for (int i(0) ; i < 8 ; i++)
			{
				if (!contact[i].EXIST())
				{
					cout << endl;
					return;
				}
				contact[i].DISPLAY();
			}
		}

		void	DISPLAY_Contact(int i)
		{
			contact[i].PRINT();
		}
};

#endif
