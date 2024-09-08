#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <istream>
#include <ostream>
#include <string>
#include <iostream>


#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
private:
	static const int MAX_MATERIAS = 4;
	AMateria *learnedMaterias[MAX_MATERIAS];

public:
	MateriaSource();
	MateriaSource(MateriaSource &m);
	~MateriaSource();

	MateriaSource &operator=(const MateriaSource &m);

	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);

};


#endif //MATERIASOURCE_HPP
