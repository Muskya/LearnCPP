/* Exercice 3 (Tableaux Char Developpez)
Écrire une fonction qui a en paramètre une chaîne de caractères
(paramètre en entrée et en sortie) et qui transforme toutes les
minuscules de la chaîne en majuscules.*/

#pragma region Includes
/*SL headers*/
	#include <iostream> 
	#include <string>
	#include <utility>
	#include <cstdlib> //for rand()
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

//functor
class Remplir { /* will increment each time its called to fill a container
				   with 1, 2, 3, 4, 5 etc... */
public:
	Remplir(int i) : m_valeur(i) {}
	int operator()() {
		++m_valeur;
		return m_valeur;
	}
private:
	int m_valeur;
};

//functor
class IncrFiveMultiplies {
public:
	inline void operator()(int& a) {
		if (a % 5 == 0) { //if can be divided by 5
			a++;
		}
	}
};

//functor
class RandomNumber {
public:
	RandomNumber() {
		//sets the seed for random numbers
		srand((unsigned)time(0));
		//we use the time as a trick to mk sure its always different
	}

	inline int operator()() const {
		return std::rand() % 25; 
		//rdm number between 0 and %x
	}
};

//functor 
class HasVowels { //checks if the passed string has Vowels
public:
	inline bool operator()(std::string const& str) const {
		for (int i = 0; i < str.size(); i++) {
			switch (str[i]) {
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
			case 'y':
				return true;
			default:
				break;
			}
		}
		return false;
	}
};

int main() {
	/* ---MORE STL ALGORITHMS/CONTAINERS/FUNCTORS PRACTICE--- */

	/*CONTAINERS*/
	vector<int> v(50);											//with 100elements
	vector<string> vs = { "Bonjour", "wtf", "dofus", "vwls", "Yes", "Cool", "DRL" };
	deque<char> d = { 'a', 'o', 't', '1', 'b' };				//could fill with generate() func
	vector<int> v1(30); vector<int> v2(30); vector<int> v3(30); //used below with transform() algorithm

	/*FUNCTORS*/
	Remplir f(0);												//fills a container incrementally
	IncrFiveMultiplies in;										//increments elements dividable by 5
	RandomNumber rdm;											//returns a random number
	HasVowels h;												//checks if input string has vowels in it

	/* ALGORITHMS */
	std::generate(v.begin(), v.end(), rdm);						/*applies a functor/fctn ptr on each
																element in a range of iterators. it fills v
																with random numbers functor here. */

	//count algorithm
	int nombre = std::count(v.begin(), v.end(), 5), i = 0;		//counts the 3rd argument value occurences
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "Iteration n=" << i << ". Value: " << *it << endl;
		i++;
	} cout << "Il y a " << nombre << " fois le chiffre 5 dans ce container.\n" << endl;


	//count_if algorithm (includes a predicat as the 3rd argument)
	int stringsWithVowels = std::count_if(vs.begin(), vs.end(), h), y = 0;
	for (vector<string>::iterator it = vs.begin(); it != vs.end(); it++) {
		cout << "Iteration n=" << y << ". Value: " << *it << endl;
		y++;
	} cout << "Il y a " << stringsWithVowels << " chaines comportant des voyelles.\n" << endl;


	//find algorithm (has a find_if equivalent usable with predicats)
	deque<char>::iterator d_it = std::find(d.begin(), d.end(), '1');
	//find() returns the container.end() iterator if it didnt find the element we're looking for
	if (d_it == d.end()) cout << "Le caractere 1 n'a pas ete trouve.\n" << endl;
	else cout << "Le caractere 1 a ete trouve.\n" << endl;


	//sort algorithm (only usable with vectors and deques
	std::sort(v.begin(), v.end()); 
	cout << "vector<int> v was sorted!" << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		if (it == v.end() - 1) cout << *it << ".";
		else cout << *it << ",";
	} cout << "\n";
	cout << "\n";

	//transform algorithm (applies a functor on 2 containers, putting result in the third)
	std::generate(v1.begin(), v1.end(), rdm); 
	std::generate(v2.begin(), v2.end(), rdm);					//filling v1 and v2 with random nb between 0 and 25
	//adds v1[i] and v2[i] into v3[i], etc...
	std::transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), std::plus<int>());
	cout << "--Affichage v1--" << endl;
	for (int i = 0; i < v1.size(); i++) cout << v1[i] << ","; cout << "\n";
	cout << "--Affichage v2--" << endl;
	for (int i = 0; i < v1.size(); i++) cout << v2[i] << ","; cout << "\n";
	cout << "--Affichage v3--" << endl;
	for (int i = 0; i < v1.size(); i++) cout << v3[i] << ","; cout << "\n";
}







