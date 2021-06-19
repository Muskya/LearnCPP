//Exercice 13
/* Écrire un programme qui demande à l'utilisateur de taper un
entier N<=20 et qui affiche la énième ligne du triangle de Pascal.
ligne 1 : 1 1
ligne 2 : 1 2 1
ligne 3 : 1 3 3 1
ligne 4 : 1 4 6 4 1
et ainsi de suite…*/

#include <iostream> 
#include <string>

#include "GlobalFunctions.h"
#include "Timespan.h"

using namespace std;

int main() {
	int a[21]; int inp;
	cout << "Entrez un entier <= 20: " << endl; cin >> inp;

	for (int i = 1; i <= inp; i++) { //une ligne du triangle
		if (i == 1) a[0] = 1; //a[0] ne bougera jamais, ce sera tjrs 1
		a[i] = 1; //dernier chiffre toujours 1 aussi. là [i] représente l'indice du dernier élément
		for (int j = i - 1; j >= 1; j--) { //remplissage entre les deux 1
			a[j] = a[j] + a[j - 1];
		} 
	}

	//affichage
	for (int i = 0; i <= inp; i++) {
		cout << a[i] << " ";
	}
	cout << endl;

}
