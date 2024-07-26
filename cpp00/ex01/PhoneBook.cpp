#include <PhoneBook.hpp>
#include "PhoneBook.hpp"


PhoneBook::PhoneBook()
	: currentIdx(0), availableContacts(0)
{}
PhoneBook::~PhoneBook()
{}

void PhoneBook::gotoNextIdx(){
	this->currentIdx = (this->currentIdx + 1) % PB_MAX_CONTACTS;
}

int	PhoneBook::addContact(Contact c){
	if (availableContacts < PB_MAX_CONTACTS){
		this->availableContacts++;
	}
	this->contacts[this->currentIdx] = c;
	int contactIdx = this->currentIdx;
	this->gotoNextIdx();
	return contactIdx;
}

Contact	*PhoneBook::findByIdx(int idx){
	if (idx < 0 || idx >= this->availableContacts){
		std::cerr << std::endl << "Error: invalid contact index! (" << idx << ")" << std::endl;
		return NULL;
	}
	return &this->contacts[idx];
}

std::string	PhoneBook::formatColumn(std::string value){
	std::string ret = value;
	if (ret.size() > 10){
		ret = ret.substr(0, 9) + '.';
	}
	return ret;
}

void	PhoneBook::showContactsList(){
	std::cout << std::endl
		<< "|" << std::setw(10) << std::right << "index"
		<< "|" << std::setw(10) << std::right << "first name"
		<< "|" << std::setw(10) << std::right << "last name"
		<< "|" << std::setw(10) << std::right << "nickname"
		<< "|" << std::endl;

	for (int i = 0; i < this->availableContacts; i++){
		Contact	*c = &this->contacts[i];
		std::cout << "|" << std::setw(10) << std::right << i;
		std::cout << "|" << std::setw(10) << std::right << this->formatColumn(c->getFirstName());
		std::cout << "|" << std::setw(10) << std::right << this->formatColumn(c->getLastName());
		std::cout << "|" << std::setw(10) << std::right << this->formatColumn(c->getNickname());
		std::cout << "|" << std::endl;
	}
}

bool	PhoneBook::getContactInfo(int idx){
	Contact	*c = this->findByIdx(idx);
	if (c == NULL){
		return false;
	}
	std::cout << std::endl;
	std::cout << "IDX:\t\t"				<< idx << std::endl;;
	std::cout << "FIRST NAME:\t"		<< c->getFirstName() << std::endl;;
	std::cout << "LAST NAME:\t"			<< c->getLastName() << std::endl;;
	std::cout << "NICKNAME:\t"			<< c->getNickname() << std::endl;;
	std::cout << "NUMBER:\t\t"			<< c->getNumber() << std::endl;
	std::cout << "DARKEST SECRET:\t"	<< c->getDarkestSecret() << std::endl << std::endl;
	return true;
}

int	PhoneBook::getAvailableContacts(){
	return this->availableContacts;
}
