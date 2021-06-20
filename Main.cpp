//Exercice 14
/* Écrire un programme qui demande à l'utilisateur de taper 6 entiers 
compris entre 0 et 10 qui seront stockés dans un tableau et qui affiche
le nombre de fois qu'on a tapé un 0, le nombre de 1, le nombre de 2… , 
le nombre de 10. */

#include <iostream> 
#include <string>

#include "GlobalFunctions.h"
#include "Timespan.h"

using namespace std;

int main() {
	int inp[6], ctr = 0, max = 10, in = 0;
	cout << "-- Remplissage du tableau --" << endl;
	for (int i = 0; i < 6; i++) {
		do {
			cout << "Entrez un entier entre 0 et 10 inclus: " << endl;
			cin >> inp[i];
		} while (inp[i] < 0 || inp[i] > 10);
	}

	for (int i = 0; i <= max; i++) { //checks one number
		ctr = 0; //the actual counter for this one number
		for (int j = 0; j < 6; j++) { //loops on the array to see if theres this one number
			if (inp[j] == i && j < 5) {
				ctr++;
			}
			if (j == 5) {
				if (inp[j] == i) {
					ctr++;
					cout << "Vous avez tape " << ctr << " fois le chiffre "
						<< i << "." << endl;
				}
				else { 
					cout << "Vous avez tape " << ctr << " fois le chiffre "
						<< i << "." << endl;
				}
			}
		}
	}

}
