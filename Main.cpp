// Basic
#include <iostream>
// C/C++ Standard Library Headers
#include <iostream>
#include <string>
// STL Headers
#include <array>
#include <vector>
#include <algorithm>
// User-Defined Headers
#include "Array.hpp"

int main() {
	Array<int, 5> arr1{ 1, 2, 3, 4, 5 };
	Array<int, 5> arr2{ 1, 2, 3, 4, 5 };

	std::cout << arr1;
	/*int a = 5;
	std::cout << &a;*/
}