#include "Harl.hpp"


static const std::string DEBUG_MSG = "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!";
static const std::string INFO_MSG = "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!";
static const std::string WARNING_MSG = " think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.";
static const std::string ERROR_MSG = "This is unacceptable! I want to speak to the manager now.";


Harl::Harl()
{}

Harl::~Harl()
{}

void Harl::debug()
{
	std::cout << DEBUG_MSG << std::endl;
}

void Harl::info()
{
	std::cout << INFO_MSG << std::endl;
}

void Harl::warning()
{
	std::cout << WARNING_MSG << std::endl;
}

void Harl::error()
{
	std::cout << ERROR_MSG << std::endl;
}

void Harl::complain(std::string level)
{
	std::string levelNames[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int i = 0;
	while (i < 4 && levelNames[i].compare(level))
		i++;
	switch (i)
	{
		case 0:
		{
			std::cout << "[ DEBUG ]" << std::endl;
			this->debug();
			std::cout << std::endl;
		}
		case 1:
		{
			std::cout << "[ INFO ]" << std::endl;
			this->info();
			std::cout << std::endl;
		}
		case 2:
		{
			std::cout << "[ WARNING ]" << std::endl;;
			this->warning();
			std::cout << std::endl;
		}
		case 3:
		{
			std::cout << "[ ERROR ]" << std::endl;
			this->error();
			std::cout << std::endl;
			break;
		}
		default:
		{
			std::cout << "[ Probably complaining about insignificant problems ]"
					  << std::endl;
			break;
		}
	}

}
