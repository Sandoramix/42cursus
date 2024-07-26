#pragma  once




#include <iostream>
#include <string>

class Harl
{
private:
	void debug(void);

	void info(void);

	void warning(void);

	void error(void);

public:
	Harl(std::string logLevel);

	Harl();

	~Harl();

	void complain(std::string level);
};



