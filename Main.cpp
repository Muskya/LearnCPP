// Basic
#include <iostream>

// C/C++ Standard Library Headers
#include <iostream>
#include <string>
// STL Headers
#include <array>
#include <vector>
// User-Defined Headers
#include "Array.hpp"

int main() {
	//Array<int, 2>* arr1 = new Array<int, 2>{ 1,2 };
	Array<int, 4> arr2{ 10, 20, 30, 40 };
	Array<int, 10> arr3{ 1, 2, 3, 4, 5,
							6, 7, 8, 9, 10 };

	
	for (int i = 0; i < arr3.size(); i++) {
		std::cout << arr3[i] << ", ";
	}
}