//Exercice 2 (Tableaux char) 
/*  */

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
		#include <map> //includes multimap.h ?
		#include <set> //includes multiset.h ?
	//...

using namespace std;

int main() {
	/* --- ITERATORS/ASSOCIATIVE CONTAINERS PRACTICE --- */

	deque<int> deq;
	deq.push_front(10); deq.push_back(20); //some filling
	deq.push_front(1);
	deque<int>::iterator deqIte;		   //= deq.begin();

	for (deqIte = deq.begin(); deqIte != deq.end(); deqIte++) {
		cout << "Affichage elements dans for avec iterateur: " << *deqIte << endl;
	} cout << "\n"; //deqIte < deq.end() is bad practice and can lead to issues. use != instead.

	deqIte = deq.begin() + 1;			   //repositions iterator at the middle (element 10);
	deq.erase(deqIte);
	for (deqIte = deq.begin(); deqIte != deq.end(); deqIte++) {
		cout << "Affichage elements dans for avec iterateur: " << *deqIte << endl;
		//only elements 1 and 20 remain.
	} cout << "\n";

	//list practice
	list<std::string> l;
	l.push_back("esports"); l.push_back("gaming"); l.push_back("knowledge");
	for (list<std::string>::iterator it = l.begin(); it != l.end(); it++) {
		cout << *it << ", ";
	} cout << "\n";
	//for list/set/map : "list<string>::iterator it = l.begin() + 3" is now allowed.
	//because iterators are bidirectional. (++, --)

	list<std::string>::iterator it = l.begin()++; 
	l.erase(it);
	for (list<std::string>::iterator it = l.begin(); it != l.end(); it++) {
		cout << *it << ", "; //second element was erased. ("gaming")
	} cout << "\n";

	//map practice
	pair<int, string> p(64, "Wood Logs"); 
	cout << p.first << endl;
	cout << p.second << endl; cout << "\n";
	//maps are made of pairs. order is always 1) KEY, 2) VALUE
	//the key is the index, usable in brackets [].
	map<string, int> m; //minecraft items used as an example (name/ID)
	m["dirt"] = 1; m["stone"] = 2; m["wood"] = 3;
	for (map<string, int>::iterator it = m.begin(); it != m.end(); it++) {
		cout << "Blocks of " << it->first << " have the ID= " << it->second << endl;
	}

	map<string, int>::iterator itMap = m.find("stone"); 
	if (itMap == m.end()) //.find() function returns the container's end() if nothing is found
		cout << "There is no value associated to the stone block" << endl;
	else
		cout << "The value associated to the stone block is " << itMap->second << endl;

	//find() function finds a value according to the passed parameter key
	//returning an iterator (which is a pair that permits access to ->first ->second attributes

}







