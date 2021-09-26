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

class Object; // Forward declaration for template parameter just below

// class that will hold a pointer. makes it a "smart pointer"
// because when the local objects of type Box will go out of scope, 
// constructor will be called and the pointer it contains will be deleted.
// we don't have to manually delete it and avoids forgetting to do it and other issues.
template <class T = Object> // Object class by default
class Box {
private:
    T* objInBox;
public:
    Box(T* obj = nullptr) : objInBox(obj) {}
    ~Box() { delete objInBox; } // Pointer's self-cleanup after going out of scope

    /* COPY SEMANTICS */
    // Copy constructor
    Box(const Box& b) {
        objInBox = new T;
        *objInBox = *b.objInBox;
    }

    // Copy assignment operator
    Box& operator=(const Box& b) {
        if (&b == this)
            return *this;

        // Release any resource we're holding first
        delete objInBox; // De-allocate memory
        objInBox = new T; // Re-allocate memory

        // Copy the resource
        *objInBox = *b.objInBox;
        return *this;
    }

    /* MOVE SEMANTICS */
    // Move constructor
    Box(Box&& b) {               // non-const lvalue reference
        objInBox = b.objInBox;  // transfer other object into this box
        b.objInBox = nullptr;   // make sure other object is not owned anymore
    }

    // Move assignment operator
    Box& operator=(Box&& b) noexcept {    // non-const lvalue reference
        if (&b == this)
            return *this;

        // Release any resource we're holding first
        delete objInBox;
        
        // Move the resource (transfer ownership)
        objInBox = b.objInBox;
        b.objInBox = nullptr;   // set object's source ownership to
                                // null, but don't delete allocated space

        return *this;
    }

    // Some operators overloading
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
    Object() { std::cout << "Object put in box." << std::endl; }
    ~Object() { std::cout << "Object in box deleted. (out of scope)" << std::endl; }
};

Box<Object> getObject() {
    Box<Object> obj(new Object());
    // this will invoke move constructor. obj is a l-value, automatically
    // returned by the function. it calls move constructor because of 
    // the c++ specification.
    return obj; 
}

int main()
{
    Box<Object> mainObj;
    mainObj = getObject(); // this will ivoke move assignment operator
}             