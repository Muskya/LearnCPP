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

/* STARTING CHAPTER M FROM LEARNCPP.COM 
https://www.learncpp.com/cpp-tutorial/intro-to-smart-pointers-move-semantics/
*/

// class that will hold a pointer. makes it a "smart pointer"
// because when the local objects of type Box will go out of scope, 
// constructor will be called and the pointer it contains will be deleted.
// we don't have to manually delete it and avoids forgetting to do it and other issues.
template <class T>
class Box {
private:
    T* objInBox;
public:
    Box(T* obj = nullptr) : objInBox(obj) {}
    ~Box() { delete objInBox; }

    //  Copy constructor that implements move semantics
    Box(Box& b) {               // must not be const
        objInBox = b.objInBox;  // transfer other object into this box
        b.objInBox = nullptr;   // make sure other object is not owned anymore
    }

    // Simple function to check pointer's ownership 
    // during operations with move semantics
    void isNull() const {
        if (objInBox == nullptr)
            std::cout << "The object in this box is null" << std::endl;
        else
            std::cout << "The object in this box is not null" << std::endl;
    }
};  

class Object {
public:
    Object() {
        std::cout << "Object put in box." << std::endl;
    }
    ~Object() {
        std::cout << "Object in box deleted. (out of scope)" << std::endl;
    }
};

int main()
{
    int x = 5;
    const int cx = 10;

    int& lref = x; // l-value reference initialized with l-value x
    const int& clref = cx; // const l-value ref allow any type of argument (l-value / r-value)

    int&& rref = 5; // r-value reference initialized with r-value 5
    int&& rref1 = lref; // r-value references can't be initialized with l-values
    const int&& crref = 10;

}             