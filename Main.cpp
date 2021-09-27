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

// Integer Wrapper class 
class IntPtr {
private:
    int* m_i;
public:
    ~IntPtr() { std::cout << "destroying integer" << std::endl; delete m_i; }
    IntPtr() = default;
    IntPtr(int i) : m_i(new int(i)) { std::cout << "creating integer" << std::endl; }

    // delete copy constructor/assignment
    IntPtr(const IntPtr& other) = delete;
    IntPtr& operator=(const IntPtr& other) = delete;

    // move constructor
    IntPtr(IntPtr&& other) noexcept
        : m_i(other.m_i)
    {
        std::cout << "move semantics constructor" << std::endl;
        other.m_i = nullptr;
    }
    // move assignment
    IntPtr& operator=(IntPtr&& other) noexcept {
        std::cout << "operator= move semantics" << std::endl;

        if (&other == this)
            return *this;

        delete m_i;
        m_i = other.m_i;
        other.m_i = nullptr;

        return *this;
    }
};

int main()
{
    IntPtr i(10);
    IntPtr a;
    

}             