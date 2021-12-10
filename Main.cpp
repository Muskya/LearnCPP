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
#include "Kata.hpp"

int main() {
	std::vector<int> list = { 1, 2, 3, 10, 20 };
	std::cout << vectorMin(list) << std::endl;
}