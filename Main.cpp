// C/C++ Standard Library Headers
#include <iostream>
#include <string>
#include <typeinfo> // type_name<decltype(x)>()
// STL Headers
#include <array>
#include <vector>
#include <algorithm>
#include <memory>
// User-Defined Headers
#include "Array.hpp"
#include "Vector.hpp"

int main() {
	// SOURCE VECTOR
	typedef std::vector<int> VEC;
	VEC* vecP = new VEC{ 1,2,3 };
	VEC vec1 = { 1, 2, 3, 5, 10, 23, 192 };

	std::cout << vec1.size() << std::endl;
	std::cout << vec1.capacity() << std::endl;
	std::cout << vec1.get_allocator().max_size() << std::endl;

	// MY VECTOR
	Vector<int> vec2(5, 5);
	for (int i = 0; i < 5; i++) {
		std::cout << vec2[i];
	}
}