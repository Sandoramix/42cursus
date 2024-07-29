#include "Zombie.hpp"
#include <sstream>

static std::string uniqueZombieName(int n, std::string name)
{
	std::ostringstream ss;
	ss << name << n;

	std::string ret = ss.str();
	return ret;
}

Zombie *zombieHorde(int N, std::string name)
{
	Zombie *allZombies = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		allZombies[i].setName(uniqueZombieName(i, name));
		allZombies[i].announce();
	}
	return allZombies;
}