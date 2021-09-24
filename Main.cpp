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
	List<int> l1;
	l1.push_back(10);
	l1.push_back(30);
	l1.push_back(40);

	//l1.print();

	l1.insert(l1.head->next, 20);

	//l1.print();

	std::cout << l1.head->getData() << std::endl;
	std::cout << l1.head->next->getData() << std::endl;
	std::cout << l1.head->next->previous->getData() << std::endl;
	std::cout << l1.tail->previous->previous->getData() << std::endl;
	std::cout << l1.tail->previous->previous->next->getData() << std::endl;
}             