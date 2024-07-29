#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>


class Brain
{
public:
	static const int IDEAS_COUNT = 100;
private:
	std::string ideas[Brain::IDEAS_COUNT];

public:
	Brain();

	Brain(Brain &b);

	~Brain();

	Brain &operator=(Brain &b);

	const std::string getIdea(int idx) const;
};


#endif //BRAIN_HPP
