#include <iostream>
#include <string>
#include <streambuf>
#include <fstream>
#include <sstream>

static bool replaceOriginal(std::string& original, std::string &search, std::string &replace) {
	bool replacedSomething = false;

	size_t start_idx = original.find(search);
	while (start_idx != std::string::npos)
	{
		replacedSomething = true;
		std::string old = original;
		original.clear();
		original.append(old.substr(0, start_idx));
		original.append(replace);
		original.append(old.substr(start_idx + search.size(), (old.size() - start_idx) + search.size()));
		start_idx = original.find(search);
	};
	return replacedSomething;
}

int main(int ac, char **av){
	if (ac != 4){
		std::cerr << "Usage: " << av[0] << " <filename> <string_to_find> <string_to_replace_with>" << std::endl;
		return 1;
	}
	std::string filename = av[1];
	std::string replaceFilename = av[1];
	replaceFilename.append(".replace");
	std::string search = av[2];
	std::string replace = av[3];

	std::ifstream file;

	file.open(filename.c_str(), std::ios::in);
	if (!file || file.fail()){
		std::cerr << "Error occurred while trying to open the file " << filename << std::endl;
		return 1;
	}

	std::ostringstream oss;
	oss << file.rdbuf();
	std::string wholeFile = oss.str();
	file.close();

	std::cout << "data: " << wholeFile << std::endl;

	std::ofstream outputFile;
	outputFile.open(replaceFilename.c_str(), std::ios::out | std::ios::trunc);
	if (!outputFile || outputFile.fail()){
		std::cerr << "Error occurred while trying to open the file " << replaceFilename << std::endl;
		return 1;
	}
	replaceOriginal(wholeFile, search, replace);
	outputFile << wholeFile;
	outputFile.close();
}