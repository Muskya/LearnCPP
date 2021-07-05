//Exercice 2 (Tableaux char) 
/*  */

/*SL headers*/
#include <iostream> 
#include <string>
	//...

/*STL headers*/
#include <algorithm>
	//containers
	#include <vector>
	#include <deque>
	#include <array>
	#include <stack>
	#include <queue> //contains priority-queue as well
	#include <list>
	//...

using namespace std;

int main() {
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

	

	
}







