#include "Character.hpp"
#include <ostream>

static const int maxLoopIterations = Character::INVENTORY_SIZE < Character::VOID_INVENTORY_SIZE ? Character::VOID_INVENTORY_SIZE : Character::INVENTORY_SIZE;

void Character::cleanInventory()
{
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		if (this->inventory[i])
			delete this->inventory[i];
		this->inventory[i] = NULL;
	}
}

void Character::cleanVoid()
{
	for (int i = 0; i < VOID_INVENTORY_SIZE; i++)
	{
		if (this->voidInventory[i])
			delete this->voidInventory[i];
		this->voidInventory[i] = NULL;
	}
	this->voidIdx = 0;
}

Character::Character() : name("UnknownCharacter"), voidIdx(0)
{
	std::cout << "[Character][DefaultConstructor][name=" << this->name << "]" << std::endl;
	for (int i = 0; i < maxLoopIterations; i++)
	{
		if (i < INVENTORY_SIZE)
			this->inventory[i] = NULL;
		if (i < VOID_INVENTORY_SIZE)
			this->voidInventory[i] = NULL;
	}

}

Character::Character(std::string name) : name(name), voidIdx(0)
{
	std::cout << "[Character][ParamConstructor][name=" << this->name << "]" << std::endl;
	for (int i = 0; i < maxLoopIterations; i++)
	{
		if (i < INVENTORY_SIZE)
			this->inventory[i] = NULL;
		if (i < VOID_INVENTORY_SIZE)
			this->voidInventory[i] = NULL;
	}
}

Character::Character(const Character &c) : voidIdx(c.voidIdx)
{
	std::cout << "[Character][CopyConstructor][name=" << this->name << "]" << std::endl;
	for (int i = 0; i < maxLoopIterations; i++)
	{
		if (i < INVENTORY_SIZE)
			this->inventory[i] = c.inventory[i]->clone();
		if (i < VOID_INVENTORY_SIZE)
			this->voidInventory[i] = c.voidInventory[i]->clone();
	}
}

Character::~Character()
{
	std::cout << "[Character][Destructor][name=" << this->name << "]" << std::endl;
	cleanInventory();
	cleanVoid();
}

Character &Character::operator=(const Character &c)
{
	if (this == &c)
	{
		return *this;
	}

	this->name = c.name;

	for (int i = 0; i < maxLoopIterations; i++)
	{
		if (i < INVENTORY_SIZE)
			this->inventory[i] = c.inventory[i]->clone();
		if (i < VOID_INVENTORY_SIZE)
			this->voidInventory[i] = c.voidInventory[i]->clone();
	}
	return *this;
}

std::string const &Character::getName() const
{
	return this->name;
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		if (!this->inventory[i])
		{
			std::cout << "[Character][name=" << this->name << "][EQUIP][materia=" << m->getType() << "][ON_SLOT=" << i
					  << "]" << std::endl;
			this->inventory[i] = m;
			return;
		}
	}
	std::cout << "[Character][EQUIP][name=" << this->name << "][materia=" << m->getType()
			  << "]: !INVENTORY_FULL! ITEM DROPPED" << std::endl;
	dropToVoid(m);
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= INVENTORY_SIZE)
	{
		std::cout << "[Character][name=" << this->name << "][UNEQUIP][slot_idx=" << idx << "]: !INVALID_INDEX!"
				  << std::endl;
		return;
	}
	AMateria *m = this->inventory[idx];
	if (!m)
	{
		std::cout << "[Character][name=" << this->name << "]" <<
				  "[UNEQUIP][slot_idx=" << idx << "]: SLOT WAS ALREADY EMPTY" << std::endl;
	}
	else
	{
		std::cout << "[Character][name=" << this->name << "]" <<
				  "[UNEQUIP][slot_idx=" << idx << "]: ITEM UNEQUIPPED [materia=" << m->getType() << "]" << std::endl;
		dropToVoid(m);
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= INVENTORY_SIZE)
	{
		std::cout << "[Character][name=" << this->name << "][USE][slot_idx=" << idx << "]: !INVALID_INDEX!"
				  << std::endl;
		return;
	}
	AMateria *m = this->inventory[idx];
	if (!m)
	{
		std::cout << "[Character][name=" << this->name << "][USE][target=" << target.getName() << "][slot_idx=" << idx
				  << "]: SLOT IS EMPTY" << std::endl;
	}
	else
	{
		std::cout << "[Character][name=" << this->name << "][USE][target=" << target.getName() << "][slot_idx=" << idx
				  << "]: ITEM USED [materia=" << m->getType() << "]" << std::endl;
		m->use(target);
	}

}

void Character::dropToVoid(AMateria *m)
{
	if (this->voidIdx == VOID_INVENTORY_SIZE - 1)
	{
		std::cout << "THERE ARE TOO MUCH MATERIAS ALL AROUND, DELETE IS IMMINENT" << std::endl;
		delete m;
		return;
	}
	this->voidInventory[this->voidIdx] = m;
	this->voidIdx = (this->voidIdx + 1) % VOID_INVENTORY_SIZE;
}
