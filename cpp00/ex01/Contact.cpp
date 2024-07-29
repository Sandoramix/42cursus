#include "Contact.hpp"

Contact::Contact()
{}

Contact::Contact(
	std::string firstName, std::string lastName,
	std::string nickname,
	std::string number,
	std::string darkestSecret
) : firstName(firstName), lastName(lastName), nickname(nickname), number(number), darkestSecret(darkestSecret)
{
}

Contact::~Contact()
{
}

// GETTERS
std::string Contact::getFirstName()
{
	return this->firstName;
}

std::string Contact::getLastName()
{
	return this->lastName;
}

std::string Contact::getNickname()
{
	return this->nickname;
}

std::string Contact::getNumber()
{
	return this->number;
}

std::string Contact::getDarkestSecret()
{
	return this->darkestSecret;
}