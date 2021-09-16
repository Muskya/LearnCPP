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
	List<unsigned __int64> l1(10, 10);
	l1.print();

	// check if list's nodes linking is correct
	std::cout << l1.head << std::endl;
	std::cout << l1.head->next << std::endl;
	std::cout << l1.head->next->previous << std::endl; //returns head address
	std::cout << l1.head->next->next << std::endl;
	std::cout << l1.head->next->next->next << std::endl;
}             