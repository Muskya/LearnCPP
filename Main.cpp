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
	std::cout << "(LearnCPP) Thread ID: " << GetCurrentThreadId() << std::endl;
	std::cout << "(LearnCPP) Process ID: " << GetCurrentProcessId() << std::endl;
	TheoDLL::doWindowsAPIStuff();
}