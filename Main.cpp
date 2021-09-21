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
	List<int>* l2 = new List<int>();
	l2->push_back(10);
	l2->push_back(20);
	l2->push_back(30);
	l2->push_back(40);
	l2->push_front(5);

	std::cout << "Print(): " << std::endl;
	l2->print(); std::cout << "\n";

	// normal iteration iterator
	std::cout << "Normal iteration iterator: " << std::endl;
	for (List<int>::iterator itF = l2->begin(); itF != l2->end(); itF++) {
		std::cout << "itF: " << itF << std::endl;
		std::cout << "*itF: " << *itF << std::endl;
	} std::cout << "\n";

	// reversed iteration iterator
	std::cout << "Reverse iteration iterator: " << std::endl;
	for (List<int>::reverse_iterator ritF = l2->rbegin();
		ritF != l2->rend(); ritF++)
	{
		std::cout << "ritF: " << ritF << std::endl;
		std::cout << "*ritF: " << *ritF << std::endl;
	} std::cout << "\n";
}             