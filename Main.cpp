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
	List<std::string> l;
	l.push_back("je");
	l.push_back("suis");
	l.push_back("Theo");
	l.print();

	l.push_front("Bonjour");	
	l.print();

	l.push_back(", ca vous surprend n'est-ce pas ?");
	l.print();
}             