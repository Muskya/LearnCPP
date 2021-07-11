#include <iostream>

// These are "object-like" macros. They can have substitution values or not.
#define HELLO_FR "Bonjour"
#define PI_VALUE 3.14
#define MY_AGE 22
#define YES true

int main() {
	// Macros testing
	std::cout << HELLO_FR << std::endl; // Will print "Bonjour" to the console
	std::cout << "Pi value is equal to " << PI_VALUE << std::endl;
	std::cout << "I was worn on the 22th of July 1999. My age is " << MY_AGE << std::endl;

	bool is_cpp_nice = YES;
	is_cpp_nice == YES ? std::cout << "Cpp is nice." : std::cout << "Cpp is not nice.";

	/* Conditional operator testing
	Only use the conditional operator for simple conditionals 
	where you use the result and where it enhances readability. */
	bool higherThan = false;
	short a = 0, b = 0;
	std::cout << "Input a and then b :" << std::endl;
	std::cin >> a; std::cin >> b;
	a > b ? higherThan = true : higherThan = false;
	if (higherThan)
		std::cout << "a is higher than b" << std::endl;
	else
		std::cout << "a is equal or lower than b" << std::endl;

	/* Const values are known/resolved at compile-time, so we should be
	* declaring them as "constexpr" for more specificity. (C++11)
	Const values that are resolved at runtime only should be declared
	as const only. */
	constexpr float gravity = 9.8;
	constexpr short sum = 10 + 5; 
}






