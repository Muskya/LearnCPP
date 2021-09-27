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
#include <utility>
// User-Defined Headers
#include "Array.hpp"
#include "Vector.hpp"
#include "List.hpp"

/* STARTING CHAPTER M FROM LEARNCPP.COM 
* https://www.learncpp.com/cpp-tutorial/intro-to-smart-pointers-move-semantics/
* Another very great reference for rvalue refs : 
* https://www.cprogramming.com/c++11/rvalue-references-and-move-semantics-in-c++11.html
*/

// some r-value functions
int getTen() {
    return 10;
}
int getTwenty() {
    return 20;
}

// use std::move(x) to cast lvalue x into a r-value reference
template <typename T>
void swap(T& a, T& b) {
    T temp = std::move(a);
    a = std::move(b);
    b = std::move(temp);
}

int main()
{
    int a = 10;
    int b = 20;

    std::cout << a << std::endl;
    std::cout << b << std::endl;

    std::cout << "swap" << std::endl;
    swap(a, b);
    // swap(getTen(), getTwenty()) doesn't work
    // swap parameters are l-value references, nothing else
    // parameters should be const T& a / const T& b to accept any parameter type

    std::cout << a << std::endl;
    std::cout << b << std::endl;
}             