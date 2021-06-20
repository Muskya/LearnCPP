//Exercice 15
/* Écrire un programme qui demande à l'utilisateur de taper le contenu
d'un tableau de réels de trois lignes et trois colonnes et qui affiche
ce tableau, mais en affichant la moyenne des éléments de chaque ligne,
de chaque colonne et la moyenne globale. */

//EXERCICE REUSSI MAIS L'AFFICHAGE POURRAIT ÊTRE OPTIMISE, ATM AVEC
//DES FLOATS/DOUBLE C'EST LA SAUCE

#include <iostream> 
#include <string>

#include "GlobalFunctions.h"
#include "Timespan.h"

using namespace std;

const int m = 3;

int main() {
	float arr[m][m];
	float avgL[m], avgC[m], avgT = 0; 
	//L = Line, C = Column, T = Total

	cout << "--Calcul de moyenne et completion d'un"
		"tableau bi-dimensionnel--" << endl;

	//remplissage tableau bi-dimensionnel
	for (int i = 0; i < 3; i++) { 
		for (int j = 0; j < 3; j++) { 
			cout << "Entrez un element pour la ligne " << i + 1
				<< " colonne " << j + 1 << endl;
			cin >> arr[i][j];
		}
	}

	cout << "\n" << endl; //helps with readability

	//Moyenne lignes - avg lines
	for (int i = 0; i < 3; i++) {
		avgL[i] = (arr[i][0]
				 + arr[i][1]
				 + arr[i][2]) / 3;
		avgT += avgL[i]; 
	} //Moyenne colonnes - avg columns
	for (int i = 0; i < 3; i++) {
		avgC[i] = (arr[0][i]
				 + arr[1][i]
			     + arr[2][i]) / 3;
		avgT += avgC[i];
	}

	avgT = avgT / (m * 2); //Calcul moyenne totale

	//Affichage - display
	for (int i = 0; i < 3; i++) { //lignes
		for (int j = 0; j < 3; j++) { //colonnes
			cout << arr[i][j]; //elements tableau bi-dimensionnel
			if (j < 2) cout << ","; else cout << "";
		}
		cout << " - Avg: " << avgL[i]; //ajout des moyennes à la fin de chaque ligne
		 //si on affiche la dernière ligne d'éléments (pour l'ajout des moyennes en bas de chaque colonne)
		if (i == 2) {
			// pas d'affichage "avg" pour les moyennes verticales (colonnes)
			cout << "\n\n";
			for (int j = 0; j < 3; j++) {
				cout << avgC[j];
				if (j < 2) cout << " "; else cout << "";
			}
		}
		cout << "\n";
	}

	cout << "Moyenne totale: " << avgT; cout << "\n";
}
