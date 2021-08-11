// C/C++ Standard Library Headers
#include <iostream>

// User-Defined Headers
#include "IntArray.h"

// This is a FUNCTION template.
template<typename T>
T Max(T a, T b) {
	return a < b ? a : b;
}

// This is a CLASS template.
// ...

int main() {
	/* TEMPLATE PRACTICE */
	int a{ 20 }, b{ 30 };
	std::string c{ "Oui" }, d{ "Bien" };

	std::cout << Max(a, b) << std::endl;
	std::cout << Max(c, d) << std::endl;

	std::cout << "\n\n";

	
}






