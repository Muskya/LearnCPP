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
	List<int>* l1 = new List<int>();
	l1->push_front(10); // head
	l1->push_back(20); // tail
	l1->push_back(30);
	l1->push_back(40);
	l1->push_back(50);
	l1->print();

	for (List<int>::iterator it = l1->begin(); it != l1->end(); it++) {
		std::cout << it << std::endl;
	}
}             