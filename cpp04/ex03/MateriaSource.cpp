#include "MateriaSource.hpp"
#include <ostream>

MateriaSource::MateriaSource()
{
	std::cout << "[MateriaSource][DefaultConstructor]" << std::endl;
	for (int i = 0; i < MateriaSource::MAX_MATERIAS; i++)
	{
		this->learnedMaterias[i] = NULL;
	}
}

MateriaSource::MateriaSource(MateriaSource &m)
{
	std::cout << "[MateriaSource][CopyConstructor]" << std::endl;
	for (int i = 0; i < MateriaSource::MAX_MATERIAS; i++)
	{
		this->learnedMaterias[i] = NULL;
		if (m.learnedMaterias[i])
			this->learnedMaterias[i] = m.learnedMaterias[i]->clone();
	}
}

MateriaSource::~MateriaSource()
{
	std::cout << "[MateriaSource][Destructor]" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &m)
{
	if (this == &m){
		return *this;
	}
	for (int i = 0; i < MateriaSource::MAX_MATERIAS; i++)
	{
		this->learnedMaterias[i] = NULL;
		if (m.learnedMaterias[i])
			this->learnedMaterias[i] = m.learnedMaterias[i]->clone();
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (!m){
		std::cout << "[MateriaSource][learnMateria]: nonexistent materia specified (NULL)" << std::endl;
		return ;
	}
	for (int i = 0; i < MateriaSource::MAX_MATERIAS; i++)
	{
		if(!this->learnedMaterias[i]){
			std::cout << "[MateriaSource][learnMateria]: learned " << m->getType() << std::endl;
			this->learnedMaterias[i] = m;
			return ;
		}
	}
	std::cout << "[MateriaSource][learnMateria]: not enough space for [" << m->getType() << "]. It's deleted now" << std::endl;
	delete m;
}

AMateria *MateriaSource::createMateria(const std::string &type)
{
	for (int i = 0; i < MateriaSource::MAX_MATERIAS; i++)
	{
		if(this->learnedMaterias[i] && this->learnedMaterias[i]->getType() == type){
			std::cout << "[MateriaSource][createMateria]: type " << type << " Found and copied" <<  std::endl;
			return this->learnedMaterias[i]->clone();
		}
	}
	std::cout << "[MateriaSource][createMateria]: type " << type << " NOT Found." <<  std::endl;
	return NULL;
}
