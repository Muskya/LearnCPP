// C/C++ Standard Library Headers
#include <iostream>
#include <string>
#include <typeinfo> 
// STL Headers
#include <array>
#include <vector>
#include <list>
#include <algorithm>
#include <memory>
// User-Defined Headers
#include "Array.hpp"
#include "Vector.hpp"
#include "List.hpp"

// debug purposes. (bad practice)
using namespace std;

int main()
{
    // --------------- STD List

    //std::list<int> l1;
    //l1.push_front(10);
    ////l1.push_back(70);
    ////l1.push_back(50);

    //for (std::list<int>::iterator it = l1.begin(); it != l1.end(); ++it)
    //{
    //    cout << &it << endl;
    //    cout << *it << endl;
    //    cout << "\n";
    //}

    //// Addresses are the same. When there is only one element,
    //// head node ptr = tail node ptr.
    //cout << &(l1.front()) << endl;
    //cout << &(l1.back()) << endl;

    // --------------- My List

    /*List<int>* l1 = new List<int>;
    l1->push_front(10);
    cout << l1->head->getData() << endl;
    cout << l1->tail->getData() << endl;
    cout << "\n";

    l1->push_front(20);
    cout << l1->head->getData() << endl;
    cout << l1->tail->getData() << endl;
    cout << "\n";

    l1->push_front(30);
    cout << l1->head->getData() << endl;
    cout << l1->head->next->getData() << endl;
    cout << l1->tail->getData() << endl;
    cout << "\n";*/

    List<int>* l2 = new List<int>;
    l2->push_back(10);
    cout << l2->head->getData() << endl;
    cout << l2->tail->getData() << endl;
    cout << "\n";

    l2->push_back(20);
    cout << l2->head->getData() << endl;
    //cout << l2->head->next->getData() << endl;
    

    //l1->push_front(20);
    //l1->display(); // 20 10

    //l1->push_back(30);
    //l1->display(); // 20 10 30

    //l1->push_back(40);
    //l1->display(); // 20 10 30 40

    //l1->push_front(50);
    //l1->display(); // 50 20 10 30 40

    //l1->push_back(60);
    //l1->display(); // 50 20 10 30 40 60

    //l1->push_back(50);
    //l1->display(); // 20 10 0 30 ...
}             