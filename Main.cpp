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

class Animal {
protected:
	const char* color = nullptr;
public:
	Animal() {
		std::cout << "Created an animal." << std::endl;
	}
	Animal(const char* col) : color(col) {
		std::cout << "Created an animal with a color." << std::endl;
	}
};

class Bird : Animal {
private:
	const char* name = nullptr;
public:
	Bird() {
		std::cout << "Created a bird." << std::endl;
	}
	Bird(const char* name) : name(name) {
		std::cout << "Created a bird with a name." << std::endl;
	}
	Bird(const char* col, const char* name)
		: Animal(col), name(name) {
		std::cout << "Created a bird with a color (from Animal constructor) and a name." 
			<< std::endl;
	}
};

int main()
{
	std::cout << "Animal a" << std::endl;
	Animal a;
	std::cout << "\n";

	std::cout << "Animal a1(\"Blue\")" << std::endl;
	Animal a1("Blue");
	std::cout << "\n";

	std::cout << "Bird b" << std::endl;
	Bird b;
	std::cout << "\n";

	std::cout << "Bird b1(\"hirondelle\")" << std::endl;
	Bird b1("hirondelle");
	std::cout << "\n";

	std::cout << "Bird b2(\"Red\", \"Chouette\")" << std::endl;
	Bird b2("Red", "Chouette");
}             