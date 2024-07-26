#pragma  once




#include <iostream>
#include <string>
#include <map>

class Harl;
typedef void (Harl::*t_harlmethod)(void);

class Harl
{
private:
	void debug(void);

	void info(void);

	void warning(void);

	void error(void);

public:
	Harl();
	~Harl();

	void complain(std::string level);
};



