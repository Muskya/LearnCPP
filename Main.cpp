#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

#include "MultiContainer.hpp"

int main() {
	MultiContainer<int>* mc1 = new MultiContainer<int>(ARR, 10);
	MultiContainer<int>* mc2 = new MultiContainer<int>(VEC);

	mc2->add_back(25);
	mc2->add_back(45);
	mc2->add_back(65);

	for (int i = 0; i < mc2->size(); i++) {
		std::cout << (*mc2)[i] << std::endl;
	}
	

	//std::cout << mc2->size() << std::endl;
}