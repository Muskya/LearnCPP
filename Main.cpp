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
	vec2[3] = 18;
	vec2[4] = 20;
	//std::cout << "vec2.at(0):" << vec2.at(0) << std::endl;	//5
	//std::cout << "vec2.at(1):" << vec2.at(1) << std::endl;	//5
	//std::cout << "vec2.at(2):" << vec2.at(2) << std::endl;	//5
	//std::cout << "vec2.at(3):" << vec2.at(3) << std::endl;	//18
	//std::cout << "vec2.at(4):" << vec2.at(4) << std::endl;	//5
	//std::cout << "front:" << vec2.front() << std::endl;		//5
	//std::cout << "back: " << vec2.back() << "\n" << std::endl;//20
	vec2.shrink_to_fit();					// Size = 5, Capacity = 5
	show(vec2);
	vec2.assign(30, 40);					// Size = 30, Capacity = 30
	show(vec2);
	vec2[29] = 100;
}