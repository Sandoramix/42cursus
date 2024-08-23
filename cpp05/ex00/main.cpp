#include "Bureaucrat.hpp"
#include <iostream>
#include <iomanip>

Bureaucrat *tryToCreate(std::string name, int grade){
	try{
		return new Bureaucrat(name, grade);
	} catch (std::exception &e){
		std::cout << "Exception occurred at Bureaucrat's creation (name="<< name << "; grade=" << grade << "): " << e.what() << "\n";
		return NULL;
	}
}

void printStats(Bureaucrat *b){
	if (!b){
		return;
	}
	std::cout << "Bureaucrat's info: "<< *b << "\n";
}

void	tryToIncrement(Bureaucrat *b){
	if (!b){
		return;
	}
	try {
		b->incrementGrade();
		std::cout << "Bureaucrat (name=" << b->getName() <<") called incrementGrade.\n\tNew grade: " << b->getGrade();
	} catch (std::exception &e){
		std::cout << "Exception occurred at Bureaucrat's incrementGrade: " << e.what() << "\n";
	}
}
void	tryToDecrement(Bureaucrat *b){
	if (!b){
		return;
	}
	try {
		b->decrementGrade();
		std::cout << "Bureaucrat (name=" << b->getName() <<") called decrementGrade.\n\tNew grade: " << b->getGrade() << "\n";
	} catch (std::exception &e){
		std::cout << "Exception occurred at Bureaucrat's decrementGrade: " << e.what() << "\n";
	}
}


void myTests(){
	std::cout << std::endl << std::setw(20) << "Valid variables" << std::setw(20) << std::endl;
	Bureaucrat *validBest = tryToCreate("PippoBest", 1);
	Bureaucrat *validWorst = tryToCreate("PippoWorst", 150);

	if (validWorst){
		Bureaucrat copyWorst(*validWorst);
		printStats(&copyWorst);
	}


	std::cout << std::endl;

	std::cout << std::endl << std::setw(20) << "Invalid variables" << std::setw(20) << std::endl;

	Bureaucrat *tooLow = tryToCreate("TooLow", 151);
	Bureaucrat *tooHigh = tryToCreate("TooHigh", -1);
	(void)tooLow;
	(void)tooHigh;

	std::cout << std::endl;

	std::cout << std::endl << std::setw(20) << "Increase/decrease test" << std::setw(20) << std::endl;
	printStats(validBest);
	tryToDecrement(validBest);
	tryToIncrement(validBest);

	std::cout << std::endl << std::setw(20) << "Increase failure test" << std::setw(20) << std::endl;
	tryToIncrement(validBest);

	std::cout << std::endl;

	std::cout << std::endl << std::setw(20) << "Decrease failure test" << std::setw(20) << std::endl;
	printStats(validWorst);



	delete validWorst;
	delete validBest;
}

int main(void){
	myTests();
}