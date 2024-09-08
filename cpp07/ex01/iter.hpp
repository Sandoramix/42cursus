#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<class T, typename Callback>
void iter(T *array, std::size_t size, void (*cb)(Callback &)){
	for(size_t i = 0; i < size; i++){
		cb(array[i]);
	}
};

#include <iostream>

#endif //ITER_HPP
