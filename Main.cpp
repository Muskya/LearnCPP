#include <iostream>
#include <cinttypes>
#include <cstddef>

/* https://CODEWARS.COM/KATA/5467e4d82edf8bbf40000155/train/cpp */
/* Your task is to make a function that can take any non-negative 
integer as an argument and return it with its digits in descending order.
Essentially, rearrange the digits to create the highest possible number.*/

typedef unsigned short int short_int;

uint64_t descendingOrder(uint64_t a) // a = 15 in this example
{
	short_int reversed = 0;
	short_int n = 0, nbDigits = 0;
	while (a != 0) {
		a /= 10; // 1: 1.5 ||| 2: 0.15
		nbDigits++;
	}
}

int main() {
	uint64_t a;
	std::cout << "Please input a number: " << std::endl;
	std::cin >> a;

	descendingOrder(a);

	return 0;
}






