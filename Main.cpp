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
	List<int>* l = new List<int>;

	l->push_back(10);
	l->push_back(20);
	l->push_back(30);

	l->print(); // outputs 10 20 30
	std::cout << "\n";

	List<int>::iterator it = l->begin();

	for (List<int>::iterator it = l->begin(); it != l->end(); it++) {
		std::cout << "it: " << it << std::endl;
		std::cout << "*it: " << *it << std::endl;
	}	// outputs :
		// 000000123456789
		// 	   10
		// 000000123456789
		// 	   20
		// 000000123456789
		//	   30

	
}             