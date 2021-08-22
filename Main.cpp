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
	Array<int, 3> arr2{ 10, 20, 30 };
	
	//iterator test
	Array<int, 5>::iterator it = arr1.begin();
	for (it; it != arr1.end(); it++) {
		std::cout << *it;
		// output: 1 2 3 4 5
	} std::cout << "\n";

	for (it = arr1.end() - 1; it >= arr1.begin(); it--) {
		std::cout << *it;
		// output: 5 4 3 2 1
	} std::cout << "\n";

	//reversed iterator test
	Array<int, 5>::reverse_iterator r_it = arr1.rbegin();
	for (r_it; r_it != arr1.rend(); r_it++) {
		std::cout << *r_it;
		//output : 5 4 3 2 1
	} std::cout << "\n";


}