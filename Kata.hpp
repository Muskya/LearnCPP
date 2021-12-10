#include <iostream>
#include <vector>
#include <algorithm>

// https://www.codewars.com/kata/577a98a6ae28071780000989/train/cpp 10 Dec 2021
int vectorMin(std::vector<int> list) {
    return *std::min_element(list.begin(), list.end());
}
int vectorMax(std::vector<int> list) {
    return *std::max_element(list.begin(), list.end());
}

// https://www.codewars.com/kata/5556282156230d0e5e000089/train/cpp 10 Dec 2021
std::string dnaToRna(std::string dna) {
	for (size_t i = 0; i < dna.length(); ++i) {
		if (dna[i] == 'T') dna[i] = 'U';
	}
	return dna;
}