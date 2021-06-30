//Exercice 1 (Tableaux Char)
/* Écrire une fonction qui a en paramètres une chaîne de caractères (paramètre en entrée)
et un entier e (paramètre en sortie). Cette fonction renvoie un booléen. La fonction renvoie
true si la chaîne de caractères est un entier écrit sous la forme d'une suite de chiffres
qui ne commence pas par 0, elle renvoie false sinon. Si la chaîne est correcte, la fonction
renvoie dans e la valeur de cet entier. */

//SL/STL headers
#include <iostream> 
#include <string>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

bool isStringInteger(char litteral[], int& e) {
	int i = 0;
	bool done = false;

	if (litteral[0] == '0')
		return done;

	while (litteral[i] != '\0') {
		if ((litteral[i] >= '1' && litteral[i] <= '9')
			|| (litteral[i] == '0' && i > 0)) //0 seulement si ce n'est pas le premier element
		{
			done = true;
			e = 10 * e + (litteral[i] - '0'); //'0' = 48 is ascii table. refer to it for further
											  //explanations.
		} 
		else {
			done = false;
		}
		i++;
	}

	return done;
}

int main() {
	//TEST RECONNAISSANCE NULL-CHARACTER//
	char litteral[] = "Hello";
	cout << litteral[4] << endl;
	if (litteral[5] == '\0') {
		cout << "dernier element == \\0" << endl;
	}
	cout << "\n\n";

	//-- TEST FONCTION EXERCICE --//
	char inp[30];		//30 chars is enough for testing
	int e = 0;			//entier passé en référence qui prendra la valeur 
						//de l'entier écrit dans la chaîne
	do {
		cout << "Entrez une phrase (max 30carac.): " << endl;
		cin >> inp;
		if (isStringInteger(inp, e)) {
			cout << "Votre phrase comprend bien une sequence d'entiers." << endl;
			cout << "Voici la chaine tapee convertie en entier: " << e << endl;
		}
		else
			cout << "Pas de sequence d'entiers detectee." << endl;
	} while (!isStringInteger(inp, e));
}







