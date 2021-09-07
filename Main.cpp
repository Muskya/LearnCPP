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
    //Box<Object> box1(new Object()); // We create one box that holds an Object (a pointer..)
    //Box<Object> box2;               /* held pointer (of type Object) will be nullptr by default
    //                                   as specified in the Box constructor */
    //box1.isNull(); // Outputs null 
    //box2.isNull(); // Outputs"not null"

    //box2 = box1;   /* Our copy/assigment implement move semantics, so it won't just make a 
    //                  copy box1 into box2. Box2 will assume ownership of the object from Box1
    //                  and thus the object in box1 will be deleted (pointer set to nullptr) */

    //std::cout << "\n";
    //box1.isNull(); // Outputs null 
    //box2.isNull(); // Outputs"not null"

    /* ---- LIST.HPP TESTS ---- */
    std::list<int> l1{ 1,2 };
    std::cout << l1.max_size() << std::endl;
    std::cout << l1.get_allocator().max_size() << std::endl;

    List<int> lm;
    //std::cout << lm.max_size() << std::endl;
}             