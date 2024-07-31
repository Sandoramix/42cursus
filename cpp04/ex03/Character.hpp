#ifndef CHARACTER_HPP
#define CHARACTER_HPP


#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
public:
	static const int INVENTORY_SIZE = 4;
	static const int VOID_INVENTORY_SIZE = 69;

private:
	std::string name;

	AMateria *inventory[INVENTORY_SIZE];

	AMateria *voidInventory[VOID_INVENTORY_SIZE];
	int voidIdx;

	void cleanInventory();
	void cleanVoid();

	void dropToVoid(AMateria *m);
public:
	Character();

	Character(std::string name);

	Character(const Character &c);

	~Character();

	Character &operator=(const Character &c);

	std::string const &getName() const;

	void equip(AMateria *m);

	void unequip(int idx);

	void use(int idx, ICharacter &target);
};


#endif //CHARACTER_HPP
