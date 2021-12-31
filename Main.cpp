// Windows API
#include <Windows.h>
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
// User-Defined Headers
// User-Defined .DLLs/.LIBs
#include "Status.h"
#include "Kata.hpp"

int main() {
	std::vector<std::string> s1 = { "hoqq", "bbllkw", "oox", "ejjuyyy", "plmiis", "xxxzgpsssa",
		"xxwwkktt", "znnnnfqknaz", "qqquuhii", "dvvvwz" }; // length: 10
	std::vector<std::string> s2 = { "cccooommaaqqoxii", "gggqaffhhh", "tttoowwwmmww" }; // length: 3

	s1 = { "ejjjjmmtthh", "zxxuueeg", "aanlljrrrxx", "dqqqaaabbb", "oocccffuucccjjjkkkjyyyeehh" };
	s2 = { "bbbaaayddqbbrrrv" };

	std::cout << MaxDiffLength::mxdiflg(s1, s2) << std::endl;
}