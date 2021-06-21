//Exercice 15
/*  */

#include <iostream> 
#include <string>

#include "GlobalFunctions.h"
#include "Character.h"
#include "Timespan.h"

using namespace std;

int main() {
	int a = 5;
	int* pA = 0;
	pA = &a;

	cout << "val a: " << a << endl;
	cout << "val &a: " << &a << endl;
	cout << "val pointeur: " << pA << endl;
	cout << "val *pointeur: " << *pA << endl;
	cout << "val &pointeur: " << &pA << endl;
}
