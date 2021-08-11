// C/C++ Standard Library Headers
#include <iostream>

// User-Defined Headers
#include "Array.hpp"
#include "SomeTemplateTests.hpp"

// This is a FUNCTION template.
template<typename T>
T Max(T a, T b) {
	return a < b ? a : b;
}

int main() {
	/* TEMPLATE PRACTICE */
	int a{ 20 }, b{ 30 };
	std::string c{ "Oui" }, d{ "Bien" };

	std::cout << Max(a, b) << std::endl;
	std::cout << Max(c, d) << std::endl;

	std::cout << "\n\n";	

	SomeTemplateTests::swap<int>(23, 49);
	std::cout << "\n";
	SomeTemplateTests::multiples<int, double>(28, 5.3, 5);
}






