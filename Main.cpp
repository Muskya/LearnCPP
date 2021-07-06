/* Exercice 2 (Tableaux Char Developpez
Écrire une fonction qui a en paramètre une chaîne de caractères
(paramètre en entrée et en sortie) et qui transforme toutes les
minuscules de la chaîne en majuscules.*/

#pragma region Includes
/*SL headers*/
	#include <iostream> 
	#include <string>
	#include <utility>
	//...
/*STL headers*/
	#include <algorithm>
		//containers
			//sequencials
			#include <vector> 
			#include <deque>
			#include <array>
			#include <stack>
			#include <queue> //contains priority-queue as well
			#include <list>
			//associatives
			#include <map> //includes multimap.h
			#include <set> //includes multiset.h
	//pre-defined STL functors
	//https://www.cplusplus.com/reference/functional/
	#include <functional>
#pragma endregion

using namespace std;

#include <iterator>

//fonction de l'exercice
void toUpper(char inp[]) {
	int i = 0;

	while (inp[i] != '\0') {
		if (inp[i] >= 'a' && inp[i] <= 'z') {
			inp[i] = inp[i] - 32; /* lowercase letter - 32 returns its uppercase 
									 version and vice-versa. refer to ASCII table. */
		}
		i++;
	}
}

int main() {
	//utilisation de la fonction
	char a[50];
	cout << "Entrez une chaine: "; cin >> a;
	toUpper(a);
	cout << "La chaine finale est: " << a << endl;
}







