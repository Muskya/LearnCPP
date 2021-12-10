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
// User-Defined .DLLs/.LIBs
#include "Status.h"

// https://www.codewars.com/kata/5556282156230d0e5e000089/train/cpp 10/Dec/2021
std::string dnaToRna(std::string dna) {
	for (size_t i = 0; i < dna.length(); ++i) {
		if (dna[i] == 'T')
			dna[i] = 'U';
	}
	return dna;
}

int main() {
	std::cout << dnaToRna("GCAT ACGT GTAT GACT GATT GACUT AAGT AGCT") << std::endl;
}