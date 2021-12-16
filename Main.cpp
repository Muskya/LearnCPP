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
// User-Defined Headers
// User-Defined .DLLs/.LIBs
#include "Status.h"

template <typename _VType, typename _Type>
void doStaticCast(_VType& value) {
	value = static_cast<_Type>(value);
}

class Base {
protected:
	int m_value{};
public:
	Base(int value) : m_value(value) {}
	virtual ~Base() = default;
};

class Derived : public Base {
protected:
	std::string m_name{};
public:
	Derived(int value, const std::string& name)
		: Base(value), m_name(name) {}
	const std::string& getName() const { return m_name; }

};

Base* getObject(bool returnDerived) {
	if (returnDerived)
		return new Derived{ 1, "Apple" };
	else
		return new Base{ 2 };
}

int main() {
	// Static and Dynamic casting tests
	double myD{ 2.5 };
	std::cout << myD << std::endl;
	doStaticCast<double, uint32_t>(myD);
	std::cout << myD << std::endl;

	Base* b{ getObject(false) };
	Derived* d = dynamic_cast<Derived*>(b);
	// if getObject() is passed a false, getName() will fail here, 
	// because we're dynamic_casting a base pointer to base object 
	// to a derived pointer, which cant be done, resulting in null pointer.
	// Thus we make sure with an if that d is not null.
	if (d) std::cout << d->getName() << std::endl;
	else std::cout << "pointer is null! dynamic_cast() failed?" << std::endl;

	delete b;
	return 0;
}