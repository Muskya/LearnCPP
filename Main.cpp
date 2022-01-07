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
#include "Kata.hpp"

void fibonacciNumbers(ull iterations) {
	ull f0 = 0, f1 = 1, fn, tmp;
	for (int i = 0; i < iterations; i++) {
		fn = f0 + f1;

		if (i == 0)
			std::cout << f0 << "\n" << f1 << std::endl;
		std::cout << fn << std::endl;

		tmp = f1;
		f1 = fn;
		f0 = tmp;
	}
}

int main() {
	//fibonacciNumbers(100);
	ProdFib::productFib(84049690);
}