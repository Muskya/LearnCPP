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

    

    // PUSH BACK TESTS
    List<int>* l2 = new List<int>;

    l2->push_back(10);
    cout << l2->head->getData() << endl;
    cout << "\n";

    l2->push_back(20);
    cout << l2->head->getData() << endl; // head
    cout << l2->head->next->getData() << endl; // tail
    cout << "\n";

    l2->push_back(30);
    cout << l2->head->getData() << endl; // head
    cout << l2->head->next->getData() << endl; // middle
    cout << l2->head->next->next->getData() << endl; // tail
    cout << "\n";

    delete l2;

    // PUSH FRONT TESTS
    List<int>* l3 = new List<int>;

    l3->push_front(10);
    cout << l3->head->getData() << endl;
    cout << "\n";

    l3->push_front(20);
    cout << l3->head->getData() << endl; // head
    cout << l3->head->next->getData() << endl; // tail
    cout << "\n";

    l3->push_front(30);
    cout << l3->head->getData() << endl; // head
    cout << l3->head->next->getData() << endl; // middle
    cout << l3->head->next->next->getData() << endl; // tail
    cout << "\n";

    delete l3;

    // PUSH FRONT / BACK MIX TESTS
    List<int>* l4 = new List<int>;
    std::cout << "\nPUSH FRONT / BACK MIX TESTS" << std::endl;

    l4->push_front(10);
    std::cout << l4->head->getData() << std::endl;
    cout << "\n";

    l4->push_back(35);
    std::cout << l4->head->getData() << std::endl;
    //std::cout << l4->tail->getData() << std::endl; // same as below
    std::cout << l4->head->next->getData() << std::endl; // tail
    cout << "\n";

    l4->push_front(100);
    std::cout << l4->head->getData() << std::endl; // head
    std::cout << l4->head->next->getData() << std::endl; // middle
    std::cout << l4->head->next->next->getData() << std::endl; // tail

    std::cout << "Size: " << l4->size() << std::endl;
    std::cout << "Max size: " << l4->max_size() << std::endl;

    l4->display();
}             