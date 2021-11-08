// Windows API
#include <Windows.h>
// C/C++ Standard Library Headers
#include <iostream>
#include <string>
#include <time.h>
#include <typeinfo>
// STL Headers
#include <array>
#include <vector>
#include <list>
#include <algorithm>
#include <memory>
#include <utility>
// User-Defined .DLLs/.LIBs
#include "Status.h"

int main()
{
	// DLL STUFF
	char inp;
	DWORD a = 50, b = 100;
	TheoDLL::Action _currentAction;

	do {
		std::cout << "Assign an action ? (y) hehe" << std::endl;
		std::cin >> inp;
	} while (inp != 'y');
	_currentAction = TheoDLL::Action::Working;
	// operator<< overloaded (in DLL) for Action type in 
	std::cout << "Action: " << _currentAction << std::endl;

	TheoDLL::sayHi("Bonjour hello hola");
	TheoDLL::swap(a, b);
	std::cout << "a=" << a << std::endl;
	std::cout << "b=" << b << std::endl;
}