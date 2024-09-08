#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>

#include "Contact.hpp"

#define PB_MAX_CONTACTS 8

class PhoneBook
{
private:
	int	currentIdx;

	Contact	contacts[PB_MAX_CONTACTS];
	int	availableContacts;

	void gotoNextIdx();
	std::string formatColumn(std::string value);

	Contact	*findByIdx(int idx);
public:
	PhoneBook();
	~PhoneBook();

	int				addContact(Contact c);
	void			showContactsList();
	bool			getContactInfo(int idx);

	int				getAvailableContacts() const;
};

#endif //PHONEBOOK_HPP
