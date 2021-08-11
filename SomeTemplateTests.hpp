#ifndef SOMETEMPLATETESTS_HPP
#define SOMETEMPLATETESTS_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class SomeTemplateTests {
public:
	// ---TEMPLATE FUNCTIONS--- //

	// Following 3 functions are template functions
	// They come from an old exercise website, but tbh these 
	// examples are super bad. I'll still write them down tho.
	// Swaps the value of given parameters
	template <typename T>
	static void swap(T a, T b) {
		std::cout << "a = " << a << ", b = " << b << std::endl;
		T temporary = a;
		a = b;
		b = temporary;
		std::cout << "a = " << a << ", b = " << b << std::endl;
	}
	// Sums up a series of multiples
	template <typename T, typename U>
	static void multiples(T sum, U x, int n) {
		int y = 0;
		for (int i = 0; i < n; i++) {
			y++;
			sum += y * x;
			std::cout << "i=" << i << std::endl;
			std::cout << "sum += " << y << "*" << x << std::endl;
		}
		std::cout << "Total sum: " << sum << std::endl;
	}
	// What the fudge is this for
	template<typename T1, typename T2>
	static T1 init(T1 num1, T1 num2, T2& start) {
		start = 1;
		return num1 + num2;
	}
};

// ---TEMPLATE CLASSES--- //

#endif

