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

void digitize(unsigned long n)
{
	std::string str = std::to_string(n);
	std::reverse(str.begin(), str.end());
	std::vector<int> rvsd;
	for (int i = 0; i < str.length(); ++i)
		rvsd.push_back(str[i] - '0');
	for (int i = 0; i < rvsd.size(); ++i)
		std::cout << rvsd[i] << std::endl;
}

int main()
{
	digitize(123456);
}