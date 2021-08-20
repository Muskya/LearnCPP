#include <iostream>

using namespace std; 

int partition(int* _Ty, int m, int d) {
	//Valeur pivot, variable d'échange
	int v, aux;
	//m et d = respectivement premier et dernier indice du tableau passé en paramètre

	//initialisation
	printf("Valeur des indices : m(%d), d(%d)\n", m, d);
	v = _Ty[m + (d - m) / 2];
	printf("La valeur pivot est donc : %d\n", v);
	printf("------------------------------------\n");

	//tant que les index ne se croisent pas
	while (m < d) { // tant que 0 < 5

		//recherche une valuer inférieure à droite
		cout << "Recherche valeur inferieure a droite\n";
		while (_Ty[d] > v) {
			printf("Valeur indice d %d\n", d);
			printf("On decremente d.\n");
			d--;
			printf("---------------\n");
		} //à la fin, d est positionné sur un indice où l'entier est < à la valeur pivot.

		//recherche une valuer supérieure à gauche
		cout << "Recherche valeur superieure a gauche\n";
		while (_Ty[m] < v) {
			printf("Valeur indice m %d\n", m);
			printf("On incremente m.\n");
			m++;
			printf("---------------\n");
		} //à la fin, m est positionné sur un indice où l'entier est > à la valeur pivot.

		if (m >= d) {
			printf("m(%d) >= (%d) alors on quitte la boucle\n", m, d);
			break;
		}

		if (_Ty[m] != _Ty[d]) {
			//échange
			cout << "Echange des valeurs\n";
			aux = _Ty[d];
			_Ty[d] = _Ty[m];
			_Ty[m] = aux;
		}
		else {
			d--;
		}
	}
	return m;
}

void tri_aux(int* _Ty, int m, int d) {
	if (m >= d) {
		return; //rien à trier
	}
	int k = partition(_Ty, m, d); //partitionne entre m et d
	tri_aux(_Ty, m, k - 1); //tri à gauche
	tri_aux(_Ty, k + 1, d); //tri à droite
}

void tri(int* _Ty, int _Size) {
	tri_aux(_Ty, 0, _Size - 1);
}

void afficher(int _Ty[], int m, int d) {
	//affichage du tableau à chaque étape
	for (int i = m; i <= d; i++) {
		printf("%d-", _Ty[i]);
	}
	printf("\n");
}

//int main()
//{
	//int tab[] = { 5, 1, 7, 2, 8, 4, 9, 13 };
	//int tab[] = { 1, 3, 7, 4, 9, 10 };
	//int tabSize = sizeof(tab) / sizeof(tab[0]);
	//tri(tab, tabSize);
	//afficher(tab, 0, tabSize - 1);
	//return 0;
//}