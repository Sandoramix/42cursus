#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>

class Contact
{
private:
	std::string firstName;
	std::string lastName;

	std::string nickname;

	std::string number;

	std::string darkestSecret;
public:
	Contact();
	Contact(std::string firstName, std::string lastName, std::string nickname, std::string number, std::string darkestSecret);
	~Contact();

	std::string	getFirstName();
	std::string	getLastName();
	std::string	getNickname();
	std::string	getNumber();

	std::string	getDarkestSecret();
};

#endif