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

void copyVector(unsigned long n)
{
	std::vector<int> myVector;
	for (int i = 0; i < n; ++i) {
		myVector.push_back(n / 10 + i);
	}
	std::vector<int> vec2;
	for (int i = myVector.size()-1; i >= 0; --i) {
		vec2.push_back(myVector[i]);
	}
}

int main()
{
	clock_t start = clock();
	copyVector(12345);
	clock_t end = clock();
	std::cout << "Took " << (float)(end - start) / CLOCKS_PER_SEC << " seconds." << std::endl;
}