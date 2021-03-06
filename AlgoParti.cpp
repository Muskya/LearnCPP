#include <iostream>

using namespace std; 

int partition(int* _Ty, int m, int d) {
	//Valeur pivot, variable d'?change
	int v, aux;
	//m et d = respectivement premier et dernier indice du tableau pass? en param?tre

	//initialisation
	printf("Valeur des indices : m(%d), d(%d)\n", m, d);
	v = _Ty[m + (d - m) / 2];
	printf("La valeur pivot est donc : %d\n", v);
	printf("------------------------------------\n");

	//tant que les index ne se croisent pas
	while (m < d) { // tant que 0 < 5

		//recherche une valuer inf?rieure ? droite
		cout << "Recherche valeur inferieure a droite\n";
		while (_Ty[d] > v) {
			printf("Valeur indice d %d\n", d);
			printf("On decremente d.\n");
			d--;
			printf("---------------\n");
		} //? la fin, d est positionn? sur un indice o? l'entier est < ? la valeur pivot.

		//recherche une valuer sup?rieure ? gauche
		cout << "Recherche valeur superieure a gauche\n";
		while (_Ty[m] < v) {
			printf("Valeur indice m %d\n", m);
			printf("On incremente m.\n");
			m++;
			printf("---------------\n");
		} //? la fin, m est positionn? sur un indice o? l'entier est > ? la valeur pivot.

		if (m >= d) {
			printf("m(%d) >= (%d) alors on quitte la boucle\n", m, d);
			break;
		}

		if (_Ty[m] != _Ty[d]) {
			//?change
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
		return; //rien ? trier
	}
	int k = partition(_Ty, m, d); //partitionne entre m et d
	tri_aux(_Ty, m, k - 1); //tri ? gauche
	tri_aux(_Ty, k + 1, d); //tri ? droite
}

void tri(int* _Ty, int _Size) {
	tri_aux(_Ty, 0, _Size - 1);
}

void afficher(int _Ty[], int m, int d) {
	//affichage du tableau ? chaque ?tape
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