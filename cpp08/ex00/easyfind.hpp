#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <set>

template<typename T>
bool easyfind(const T &container, int value){
	return std::find(container.begin(), container.end(), value) != container.end();
}



#endif //EASYFIND_HPP
