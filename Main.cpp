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
#include <utility>
// User-Defined Headers
#include "Array.hpp"
#include "Vector.hpp"
#include "List.hpp"

/* STARTING CHAPTER M FROM LEARNCPP.COM 
* https://www.learncpp.com/cpp-tutorial/intro-to-smart-pointers-move-semantics/
* Another very great reference for rvalue refs : 
* https://www.cprogramming.com/c++11/rvalue-references-and-move-semantics-in-c++11.html
*/

class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

unsigned int countBits(unsigned long long n) {
	std::string binary;
	int nb = 0;
	int remain = 0;

	while (n % 2 == 0 || n % 2 == 1) {
		remain = n % 2; 
		if (remain == 0)
			binary.insert(0, "0");
		if (remain == 1)
			binary.insert(0, "1");
		n = n / 2;
	}
}

int main()
{
	countBits(4);

	// most common smart pointer
	// don't allocate it on the heap (dynamic allocation), otherwise it might
	// not be properly deallocated, thus not being deleted after going out of 
	// scope as initially expected.
	std::unique_ptr<Resource> up1(new Resource);
	std::unique_ptr<Resource> up2 = nullptr;

	std::cout << "up1 is: " << (up1 != nullptr ? "not null\n" : "null\n");
	std::cout << "up2 is: " << (up2 != nullptr ? "not null\n" : "null\n");

	//up2 = up1; // Won't compile, copy assignment is disabled with std::unique_ptr 
	//(copy constructor too). since up2 is not a r-value, we need to use std::move.
	up2 = std::move(up1);	//up2 takes ownership of up1's Resource. up2's Resource
							//is destroyed, and up1 is sett to null. (must not be de-allocated)

	std::cout << "Ownership transferred\n";

	std::cout << "up1 is " << (up1 != nullptr ? "not null\n" : "null\n");
	std::cout << "up2 is " << (up2 != nullptr ? "not null\n" : "null\n");		
} // up2's Resource destroyed because going out of scope here.