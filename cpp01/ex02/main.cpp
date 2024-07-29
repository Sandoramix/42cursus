#include <iostream>
#include <string>


int main()
{
	std::string s1 = "HI THIS IS BRAIN";
	std::string *stringPTR = &s1;
	std::string &stringREF = s1;

	std::cout << "s1 address:\t\t" << &s1 << std::endl;
	std::cout << "stringPTR address:\t" << stringPTR << std::endl;
	std::cout << "stringREF address:\t" << &stringREF << std::endl;

	std::cout << "-----------------------------" << std::endl;

	std::cout << "s1 value:\t\t" << s1 << std::endl;
	std::cout << "stringPTR value:\t" << *stringPTR << std::endl;
	std::cout << "stringREF value:\t" << stringREF << std::endl;

}