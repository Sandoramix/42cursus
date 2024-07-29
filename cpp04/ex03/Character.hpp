#ifndef CHARACTER_HPP
#define CHARACTER_HPP


#include "ICharacter.hpp"

class Character: public ICharacter
{

public:
	Character();
	Character(const Character &c);
	~Character();

	Character &operator=(const Character &c);

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};


#endif //CHARACTER_HPP
