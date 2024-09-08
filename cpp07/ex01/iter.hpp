#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<class T>
void iter(T *array, std::size_t size, void (*cb)(const T &)){
	for(size_t i = 0; i < size; i++){
		cb(array[i]);
	}
};

template<class T>
void iter(T *array, std::size_t size, void (*cb)(T &)){
	for(size_t i = 0; i < size; i++){
		cb(array[i]);
	}
}


#include <iostream>

#endif //ITER_HPP
