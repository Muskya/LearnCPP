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
	typedef std::vector<int> vec;
	//vec vec1 = { 1, 2, 3, 5, 10, 23, 192 };
	//show(vec1);								// size = 7, capacity = 7
	//vec1.insert(vec1.cend(), { 1,2,3 });	
	//show(vec1);								// size = 10, capacity = 10
	//vec1.clear();							// removes everything, keeps capacity
	//show(vec1);								// size = 0, capacity = 10
	//vec1.reserve(15);
	//show(vec1);								// size = 0, capacity = 15
	//vec1.resize(10);						// size = 10, capacity = 15
	////vec1[10] = 10; not ok: vec has size of 10, from index [0] to [9]
	//vec1[9] = 50;	// ok
	//show(vec1);
	//vec vec1 = { 1, 2, 3 };
	//vec1.insert(vec1.begin(), 10);
	//show(vec1);								// 10, 1, 2, 3

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
	vec2.clear();
	vec2.shrink_to_fit();
	show(vec2);
	/*int* ptrTest = nullptr;
	vec2.get_allocator().deallocate(&vec2.data()[0], 100);
	for (int i = 0; i < 100; i++) {
		ptrTest = (&vec2.data()[i]);
		std::cout << ptrTest << std::endl;
	}*/
	vec2.resize(3);
	vec2[0] = 10;
	vec2[1] = 20;
	vec2[2] = 30;
	show(vec2);							// 10, 20, 30,
	vec2.insert(vec2.begin() + 1, 22);	
	show(vec2);							// 10, 22, 20, 30,
	vec2.insert(&vec2.data()[3], 50);
	show(vec2);							// 10, 22, 20, 50, 30,
	vec2.pop_back();
	show(vec2);							// 10, 22, 20, 50,
	vec2.push_back(2000);
	show(vec2);							// 10, 22, 20, 50, 2000
	vec2.emplace_back(33, 44, 55);
	show(vec2);
}