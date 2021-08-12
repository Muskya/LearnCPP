// C/C++ Standard Library Headers
#include <iostream>

// User-Defined Headers
#include "Array.hpp"

// This is a CLASS template
// class T = array data type
// int size = array size
// Example of a template class with a template type parameter (T)
// and a template non-type parameter (int size). Works with functions too.
template <class T, int size>
class StaticArray {
private:
	T arr[size];
public:
	T* getArray() const;
	inline T& operator[](int index) {
		return arr[index];
	}
};

template <class T, int size>
T* StaticArray<T, size>::getArray() const {
	return arr;
}

int main() {
	StaticArray<double, 10> sa;
	sa[0] = 3.5; sa[1] = 4;

	std::cout << sa[0] << std::endl;
}






