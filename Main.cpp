#include <iostream>
#include <cinttypes>
#include <cstddef>
#include <vector>
#include <algorithm>

/* https://CODEWARS.COM/KATA/5467e4d82edf8bbf40000155/train/cpp */
/* Your task is to make a function that can take any non-negative 
integer as an argument and return it with its digits in descending order.
Essentially, rearrange the digits to create the highest possible number.*/

typedef unsigned short int short_int;

void descendingOrder(uint64_t a) // a = 1021 in this example
{
	short_int
		remainder	= 0,		//	Remainder (last digit of the number at each iteration)
		maxDigit	= 0,		//	Digit that will go first
		descending	= 0;		//  Final descending number

	std::vector<short_int> rest;

	while (a != 0) {
		remainder = a % 10; 
		std::cout << "Remainder: " << remainder << std::endl; 
		if (remainder > maxDigit) {
			if (maxDigit == 0) {}
			else { rest.push_back(maxDigit); }
			maxDigit = remainder; 
			descending = descending * 10 + maxDigit;
		} else {
			rest.push_back(remainder);
		}
		a /= 10;
	}

	while (rest.size() > 1) {
		descending = (descending * 10) + *max_element(rest.begin(), rest.end());
		rest.erase(max_element(rest.begin(), rest.end()));
	}
	descending = descending * 10 + rest.front(); // Final addition

	std::cout << "Number input in descending order:" << std::endl;
	std::cout << descending << std::endl;
}

int main() {
	uint64_t a;
	std::cout << "Please input a number: " << std::endl;
	std::cin >> a;

	descendingOrder(a);

	return 0;
}






