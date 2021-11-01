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

void copyVector(unsigned long n)
{
	std::vector<int> myVector;
	for (int i = 0; i < n; ++i) {
		myVector.push_back(n / 10 + i);
	}
	std::vector<int> vec2;
	for (int i = myVector.size()-1; i >= 0; --i) {
		vec2.push_back(myVector[i]);
	}
}

int main()
{
	constexpr int dim = 3;
	int l = 3, c = 3;
	int calcul_indice;
	int A[dim][dim] = { {2, 1, 5},
						{0, 5, 4},
						{6, 1, 7} };

	int B[dim][dim] = { {10, 1, 1},
						{1, 2, 3},
						{4, 4, 0} };

	int C[dim][dim] = { {0, 0, 0},
						{0, 0, 0},
						{0, 0, 0} };

	for (int i = 0; i < dim; ++i) {
		for (int j = 0; j < dim; ++j) {
			for (int k = 0; k < dim; ++k) {
				// Le calcul est :
				// ( A[0][0] * B[0][0] ) +
				// ( A[0][1] * B[1][0] ) +
				// ( A[0][2] * B[2][0] )
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}

	// Affichage
	for (int i = 0; i < dim; ++i) {
		for (int j = 0; j < dim; ++j) {
			std::cout << C[i][j] << " ";
		}
		std::cout << "\n";
	}
	// Devrait montrer :
	/* 
	*  41 24 5
	*  21 26 15
	*  89 36 9
	*/
}