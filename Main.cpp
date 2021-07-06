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

using namespace std;

class Addition { /* Functor or Function-object class. Object with 
				    "object()" call allowed.*/
public:
	inline int operator()(int a, int b) {
		return a + b;
	}
};

class Add5ToPairs {
public:
	inline int operator()(int& a) {
		if (a % 2 == 0) {
			cout << a << " est pair. Ajoutons 5." << endl;
			return a += 5;
		}
		else {
			cout << a << " n'est pas pair." << endl;
			return a;
		}
	}
};

class CompareLength {
public:
	inline bool operator()(std::string a, std::string b) const {
		return a.length() < b.length();
	}
};

int main() {
	/* ---PRACTICE FUNCTORS--- */
	Addition ope1;
	cout << "--Affichage foncteur simple d'addition--" << endl;
	cout << "10 + 30 = " << ope1(10, 30) << endl; cout << "\n";

	Add5ToPairs add5;
	vector<int> nbVec;
	nbVec.push_back(3); nbVec.push_back(2); nbVec.push_back(10);
	nbVec.push_back(102); nbVec.push_back(783);
	cout << "--Affichage foncteur adding 5 to pairs--" << endl;
	for (vector<int>::iterator it = nbVec.begin(); it != nbVec.end(); it++) {
		add5(*it); //add 5 if the vector's current element is pair.
		cout << "Nouvelle valeur: " << *it << endl;
	} cout << "\n";

	map<string, int, CompareLength> m;
	/*map constructor can take a new predicat functor instead
	of the "<" default one. instead of sorting the given elements
	alphabetically, it will compare the size of the string keys 
	to sort the map. */
	m["SoulSand Block"] = 3;
	m["Wood Logs"] = 1;
	m["Enchanted Diamond Sword"] = 10;
	m["Stone Bricks"] = 2;
	
	cout << "--Affichage elements Map--" << endl;
	for (map<string, int>::iterator it = m.begin(); it != m.end(); it++) {
		cout << it->first << " elements have the ID " << it->second << endl;
		//string keys are sorted by size, starting with "Wood Logs".
	}

}







