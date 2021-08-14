#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

#include "MultiContainer.hpp"

int main() {
	MultiContainer<int>* mc1 = new MultiContainer<int>(ARR, 10);
	MultiContainer<int>* mc2 = new MultiContainer<int>(VEC);

	for (int i = 0; i < 10; i++) {
		(*mc2)[i] = i + i;
	}

	std::cout << (*mc2)[2] << std::endl;
	//std::cout << mc2->size() << std::endl;
}