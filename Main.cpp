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

int main()
{
    /*std::list<int>* l1 = new std::list<int>;
    l1->push_front(10);
    l1->push_front(20);
    for (auto it = l1->begin(); it != l1->end(); it++) {
        std::cout << *it << std::endl;
    }
    
    std::cout << l1->size() << std::endl;*/

    List<int>* l1 = new List<int>;
    l1->push_front(10);

    std::cout << l1->head->data << std::endl;
    std::cout << l1->tail->data << std::endl;

    l1->push_front(25);

    std::cout << "\n" << l1->head->data << std::endl;
    std::cout << l1->head->next->data << std::endl;
    std::cout << l1->head->next->next->data << std::endl;
    
    l1->push_front(40);

    std::cout << "\n" << l1->head->data << std::endl;
    std::cout << l1->head->next->data << std::endl;
    std::cout << l1->head->next->next->data << std::endl;
    std::cout << l1->head->next->next->next->data << std::endl;

    std::cout << "\n" << l1->size() << std::endl;
}             