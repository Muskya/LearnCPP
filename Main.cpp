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
	//...

using namespace std;

int main() {
	//vector practice
	cout << "-- VECTOR PRACTICE --" << endl;
	std::vector<int> vec;
	vec.assign(30, 100); vec.push_back(200);
	cout << vec.back() << endl;
	cout << vec.front() << endl;
	vec.pop_back();
	cout << vec.back() << endl;
	cout << "\n";

	//deque practice (can use push_front and push_back
	//to add elements at the beginning or at the end here)
	cout << "--DEQUE PRACTICE--" << endl;
	std::deque<int> deq;
	deq.assign(10, 50);//fills the deque with n=50 10 times
	for (int i = 0; i < deq.size(); i++) {
		cout << "Indice " << i << ": " << deq[i] << endl;
	} 
	deq.push_front(20); deq.push_back(80);
	cout << "\npush_front(20) et push_back(80)" << endl;
	for (int i = 0; i < deq.size(); i++) {
		cout << "Indice " << i << ": " << deq[i] << endl;
	}
	cout << "\n";

	//stack practice LIFO (last in first out) principle
	//can only access last element
	cout << "--STACK PRACTICE--" << endl;
	std::stack<int> sta;
	cout << "Ajout dans l'ordre des valeurs: 1, 10, 100" << endl;
	sta.push(1); //adds "1" to the top of the pile (above null/0)
	sta.push(10); //adds "10" to the top of the pile (above 1)
	sta.push(100); //adds "100" to the top of the pile (above 10)
	cout << "Dernier element de la pile ajoute: " << sta.top() << endl;
	cout << "Suppresion du dernier element" << endl; sta.pop();
	cout << "Dernier element de la pile: " << sta.top() << endl;
	cout << "\n";

	//queue practice FIFO (first in first out) principle
	//acts as the opposite of the stack (kind of)
	cout << "--QUEUE PRACTICE--" << endl;
	std::queue<int> que;
	cout << "Ajout dans l'ordre des valeurs: 1, 10, 100" << endl;
	que.push(1); que.push(10); que.push(100);
	cout << "que.front(): " << que.front() << endl;
	//front() = premier element ajouté mais qui se retrouve à la fin car FIFO
	cout << "que.back(): " << que.back() << endl;
	cout << "\n";

	//priority-queue practice FIFO (same as queue but with desc. sorting)
	cout << "--PRIORITY-QUEUE PRACTICE--" << endl;
	std::priority_queue<int> pQue;
	cout << "Ajout dans l'ordre des valeurs: 1, 10, 100" << endl;
	pQue.push(283); pQue.push(7000); pQue.push(10);
	cout << "pQue.top(): " << pQue.top() << endl; //only top(). no front() or back()
	cout << "the push() calls were sorted descendly, the top value being the highest one." << endl;
	// the operator<() needs to be redefined in order to work with other value types
	// or of the user wants the sorting with numbers to be ascedent instead of descendant

}







