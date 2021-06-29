//Exercice 1 (Tableaux Char)
/*  */

//standard library headers
#include <iostream> 
#include <string>
#include <vector>
#include <array>

using namespace std;

int main() {

	// ----------------- ITERATORS PRACTICE ---------------- //

	std::array<char, 6> const mot{ 'C','H','E','V','A','L' }; //some const char array
	std::array<char, 6>::const_iterator debut{ mot.begin() }; //beginning iterator (needs to be constant
	//because it operates on a const container)
	auto fin{ mot.end() }; //ending iterator (used auto here)

	std::vector<int> chiffres{ 10, 20, 100, 500, 10000, 55555 }; //some int vector
	std::vector<int>::iterator iterChiffresDebut{ chiffres.begin() }; //beginning iterator (not used here)
	std::vector<int>::iterator iterChiffresEnd{ chiffres.end() - 1 }; //ending iterator.
	//the ending iterator points to the container.lastElement() + 1 which means a null-value place so that we're sure
	//we've reached the end of the container/collection. when using its value we must then proceed to decrement
	//it at least once otherwise the compiler will be ANGRY af.

	//ITERATORS ARE POINTERS so we need to dereference them with * to use them properly.

	//Iterates through "array<char, 6> mot" with a precedently declared iterator
	cout << "Affichage de \"array<char,6> mot\" with for avec iterateurs debut et fin" << endl; 
	for (debut; debut < fin; debut++)
		cout << *debut;
	cout << "\n\n";

	//Iterates through "vector<int> chiffres" with a local iterator created in the loop
	cout << "Affichage de \"vector<int> chiffres\" with for avec iterateur cree localement" << endl;
	for (std::vector<int>::iterator it{ chiffres.begin() }; it != chiffres.end(); it++)
		cout << *it << endl;
	cout << "\n";

	//Iterates reversely (rbegin = reverse begin, rend = reverse end)
	cout << "Affichage de \"vector<int> chiffres\" a l'envers avec rbegin()/rend()" << endl;
	for (auto it{ chiffres.rbegin() }; it != chiffres.rend(); ++it)
		std::cout << *it << std::endl;
	cout << "\n";

	--iterChiffresEnd; //could also initialize the iterator to "chiffres.end() - 1" earlier.
	cout << "Affichage dernier element \"vector<int> chiffres\" en decrementant iterator initialise a end()" << endl;
	cout << *iterChiffresEnd << endl; //should output the last element of vector<int> chiffres (55555).
	cout << "\n";

	cout << "Creation d'un container sous-ensemble de \"vector <int> chiffres\" avec les elements 3/4/5 (indices 2/3/4)" << endl;
	std::vector<int> sousChiffres{ chiffres.begin() + 2, chiffres.begin() + 5 };
	for (int element : sousChiffres)
		cout << element << ", ";
	cout << "\n";
}








