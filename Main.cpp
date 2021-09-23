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
	List<int>* l1 = new List<int>(5, 10);
	l1->print();

	std::cout << l1->size() << std::endl;
	std::cout << l1->maxsize() << std::endl;
}             