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


/* !----MOVE SEMANTICS PRACTICE----! */

/* --LEARNT-- */
// perfect forwarding: 


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

    //  Assignment operator overload that implements move semantics
    Box& operator=(Box& b) {
        // Returns this object if passed Box ref is this
        if (&b == this)
            return *this;

        delete objInBox;
        objInBox = b.objInBox;
        b.objInBox = nullptr;

        return *this;
    }

    T& operator*() const { return *objInBox; }
    T* operator->() const { return objInBox; }

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
    List<int> l1;
    l1.push_back(10);
}             