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

// vector debug purpose
template <class T>
void show(const std::vector<T>& vec1) {
	std::cout << "--MSVC VECTOR--" << std::endl;
	std::cout << "size:" << vec1.size() << std::endl;
	std::cout << "capacity:" << vec1.capacity() << std::endl;
	std::cout << "max_size:" << vec1.max_size() << std::endl;
	std::cout << "allocator max size:" << vec1.get_allocator().max_size()
		<< std::endl;
	vec1.empty() ? std::cout << "empty" << std::endl : std::cout << "not empty"
		<< std::endl;
	std::cout << "values:" << std::endl;
	for (int i = 0; i < vec1.size(); i++) {
		std::cout << vec1[i] << ",";
	}
	std::cout << "\n\n";
}
template <class T>
void show(Vector<T>& vec1) {
	std::cout << "--MY VECTOR--" << std::endl;
	std::cout << "size:" << vec1.size() << std::endl;
	std::cout << "capacity:" << vec1.capacity() << std::endl;
	//std::cout << "max_size:" << vec1.max_size() << std::endl;
	std::cout << "allocator max size:" << vec1.get_allocator().max_size()
		<< std::endl;
	vec1.empty() ? std::cout << "empty" << std::endl : std::cout << "not empty"
		<< std::endl;
	std::cout << "values:" << std::endl;
	for (int i = 0; i < vec1.size(); i++) {
		std::cout << vec1.m_data[i] << ",";
	}
	std::cout << "\n\n";
}

int main() {
	// MSVC VECTOR TESTS
	//typedef std::vector<int> VEC;
	//VEC vec1 = { 1, 2, 3, 5, 10, 23, 192 };
	//show(vec1);								// Size = 7, Capacity = 7
	//vec1.insert(vec1.cend(), { 1,2,3 });	
	//show(vec1);								// Size = 10, Capacity = 10
	//vec1.clear();							// Removes everything, keeps capacity
	//show(vec1);								// Size = 0, Capacity = 10
	//vec1.reserve(15);
	//show(vec1);								// Size = 0, Capacity = 15
	//vec1.resize(10);						// Size = 10, Capacity = 15
	////vec1[10] = 10; NOT OK: vec has size of 10, from index [0] to [9]
	//vec1[9] = 50;	// OK
	//show(vec1);

	// MY VECTOR TESTS
	Vector<int> vec2(5, 5);					// Vector with five '5'
	show(vec2);								// Size / Capacity = 5
	vec2.reserve(10);						// Allocated storage is now 10
	show(vec2);								// Size = 5, Capacity = 10
	vec2[4] = 10;
	show(vec2);
	vec2.clear();
	show(vec2);
	//vec2.clear();
	//show(vec2);								// Size = 0, Capacity = 10
	//vec2[1] = 10;
	//show(vec2);
}