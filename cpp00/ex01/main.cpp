#include <PhoneBook.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <limits>

typedef enum cmd
{
	INVALID,
	ADD,
	SEARCH,
	EXIT
} InputValue;

static InputValue parsePromptInput(std::string input)
{
	if (input == "ADD" || input == "add")
		return ADD;
	if (input == "SEARCH" || input == "search")
		return SEARCH;
	if (input == "EXIT" || input == "exit")
		return EXIT;
	return INVALID;
}

static void prompt()
{
	std::cout
		<< std::endl << "CMDS:" << std::endl
		<< "  ADD: save a new contact" << std::endl
		<< "  SEARCH: display a specific contact" << std::endl
		<< "  EXIT" << std::endl
		<< ": ";
}

static std::string getContactValue(std::string attr)
{
	std::string input;

	std::cout << attr << ": ";
	std::getline(std::cin, input);
	if (std::cin.eof() || input.empty())
	{
		if (std::cin.eof())
		{
			input.clear();
			std::cin.clear();
			fflush(stdin);
			// someone EOF'ed
			std::cerr << "Someone EOF'ed..." << std::endl;
		}
		else if (input.empty())
		{
			std::cerr << "Input cannot be empty" << std::endl;
		}
		return getContactValue(attr);
	}
	return input;
}

int main(int ac, char **av)
{
	(void) ac;

	PhoneBook book;

	//Contact a("aaaaaaaaaaaaaaaaaaaaaaaa", "a", "a", "a", "a");
	//Contact b("b", "b", "b", "b", "b");
	//Contact c("c", "c", "c", "c", "c");
	//Contact d("d", "d", "d", "d", "d");
	//book.addContact(a);
	//book.addContact(b);
	//book.addContact(c);
	//book.addContact(d);
	//book.showContactsList();

	//book.getContactInfo(-1);
	//book.getContactInfo(7);
	//book.getContactInfo(1);

	std::string input;

	std::cout << av[0] << " started!" << std::endl;

	bool loop = true;
	while (loop)
	{
		input.clear();
		prompt();
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			input.clear();
			std::cin.clear();
			std::cerr << std::endl << "Someone EOF'ed..." << std::endl;
			break;
		}
		InputValue type = parsePromptInput(input);
		switch (type)
		{
			case ADD:
			{
				std::string fName = getContactValue("First Name");
				std::string lName = getContactValue("Last Name");
				std::string nickname = getContactValue("Nickname");
				std::string number = getContactValue("Number");
				std::string darkestSecret = getContactValue("Darkest secret");

				int contactIdx = book.addContact(Contact(fName, lName, nickname, number, darkestSecret));
				std::cout << std::endl << "Contact added! idx: " << contactIdx << std::endl;
				break;
			}
			case SEARCH:
			{
				book.showContactsList();
				int availableContacts = book.getAvailableContacts();
				if (availableContacts == 0)
				{
				}
				else
				{
					int choice;

					std::cout << std::endl
							  << "Select contact index [0 - " << availableContacts - 1 << "]"
							  << std::endl << ": ";

					std::string searchInput;
					std::getline(std::cin, searchInput);
					choice = atoi(searchInput.c_str());

					book.getContactInfo(choice);
				}
				break;
			}
			case EXIT:
			{
				loop = false;
				break;
			}
			case INVALID:
				break;
		}
	}
}