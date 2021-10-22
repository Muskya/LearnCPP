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

// KATA : https://www.codewars.com/kata/526571aae218b8ee490006f4

unsigned int countBits(unsigned long long n) {
	if (n == 0)
		return 0;
	unsigned int count = 0;
	std::cout << "start n: " << n << std::endl;
	std::vector<unsigned int> T;
	do {
		T.push_back(n % 2);
		n /= 2;
	} while (n / 2 != 0);
	T.push_back(1);
	for (auto p = T.begin(); p != T.end(); ++p) {
		if (*p == 1) {
			count++;
		}
	}

	return count;
}

int main()
{
	std::cout << countBits(1555) << std::endl;
}