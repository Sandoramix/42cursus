
#pragma once




#include <iostream>
#include <string>

class Zombie
{
private:
	std::string name;

public:
	Zombie(std::string name);
	~Zombie();

	void	announce(void);
};

void randomChump(std::string name);
Zombie	*newZombie(std::string  name);

