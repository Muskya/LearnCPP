#include <iostream>
#include <cinttypes>
#include <string>
#include <algorithm>

/* https://CODEWARS.COM/KATA/5467e4d82edf8bbf40000155/train/cpp */
/* Your task is to make a function that can take any non-negative 
integer as an argument and return it with its digits in descending order.
Essentially, rearrange the digits to create the highest possible number.*/


// // // // SOLUTION // // // //
uint64_t descendingOrder(uint64_t a)
{
	std::string s = std::to_string(a);
	std::sort(s.rbegin(), s.rend());
	return std::stoull(s);
}

int main() {
	uint64_t a;
	std::cout << "Please input a number: " << std::endl;
	std::cin >> a;

	std::cout << "Number input in descending order: " << descendingOrder(a) << std::endl;

	return 0;
}






