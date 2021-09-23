// C/C++ Standard Library Headers
#include <iostream>
#include <string>
#include <typeinfo> 
// STL Headers
#include <array>
#include <vector>
#include <list>
#include <algorithm>
#include <memory>
// User-Defined Headers
#include "Array.hpp"
#include "Vector.hpp"
#include "List.hpp"

int main()
{
	List<int> l1(10, 20);
	for (int val : l1) {
		std::cout << val << std::endl;
		std::cout << &val << std::endl;
	}

	//List<int>* l2 = new List<int>(10, 5); // dynamically allocated list
	//for (int val2: l2) : doesn't work. l2 is a pointer.

	List<const char*> l2(3, "bonjour");
	for (const char* a : l2) {
		std::cout << a << std::endl;
		std::cout << &a << std::endl;
	}
}             