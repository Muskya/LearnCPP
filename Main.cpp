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
	Array<int, 3> arr1{ 1, 2, 3 };
	Array<int, 3> arr2{ 10, 20, 30 };
	arr1.show(); arr2.show();

	std::cout << "\nSwap!" << std::endl;
	arr1.swap(arr2);
	arr1.show(); arr2.show();
}