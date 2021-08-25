// std::vector Implementation by Théo R.
// 24th August 2021 
// Vector.hpp

/* REFERENCES:
* https://devdocs.io/cpp/container/vector
* https://gcc.gnu.org/onlinedocs/gcc-4.8.0/libstdc++/api/a01638_source.html
* https://en.cppreference.com/w/cpp/container/vector
* https://www.tutorialspoint.com/cpp_standard_library/vector.htm
* https://hadibrais.wordpress.com/2013/11/10/dissecting-the-c-stl-vector-part-1-introduction/
* MSVC's vector souce file (C:\Program Files (x86)\Microsoft Visual Studio\2019\
  Community\VC\Tools\MSVC\14.28.29910\include\vector)
*/

// Details learnt while writing this implementation :
/*	Contiguous:		touching a common border; touching; next to each-other;
*	<typeinfo>:		Type_info returned by typeid is just an rvalue about a type,
*					while type returned by decltype can be used in the same way as other
*					predefined types (e.g. declare entities)
*					https://www.geeksforgeeks.org/type-inference-in-c-auto-and-decltype/
*	Allocator:		Allows customized memory allocation/deallocation. Mostly used in 
*					STL containers to optimize containers' elements' memory allocations instead
*					of using new / delete.
*	Polymorphic-
*	allocator:		std::pmr::polymorphic_allocator is a special allocator whose allocation
*					behavior depends on the memory resource it is constructed with.
*   ptrdiff_t:      it is the type returned by the substraction of two pointers. it's 
*                   generally used for loop counters, array indexing, size storage, 
*                   and of course adressing/pointer arithmetic. (long long __int64)
*   explicit:       C++ keyword that specifies that a constructor with a single parameter
*                   (called a converting constructor), cannot be used for implicit conversion
*                   and copy-initialization. 
*                   https://stackoverflow.com/questions/121162/what-does-the-explicit-keyword-mean
*   
*/

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cassert>          // assert()
#include <algorithm>        // lexicographical_compare() 
#include <iostream> 
#include <memory>			// Allocators

template <class _Ty, class Allocator = std::allocator<_Ty>>
class Vector {
public:
    using value_type                = _Ty;
    using pointer                   = _Ty*;
    using reference                 = _Ty&;
    using alty                      = std::allocator<_Ty>;
    using size                      = std::size_t;
    using difference_type           = std::ptrdiff_t;   // Pointer arithmetic
    using iterator                  = pointer;
    using const_iterator            = const iterator;
    using reverse_iterator          = std::reverse_iterator<iterator>;

    // FIELDS
    size m_size;                    //  Current size of the vector (nb of elements)
    size m_capacity;                //  Maximum capacity of the vector (bytes)
    pointer m_data;                 //  Underlying C-Array
    std::allocator<_Ty> m_alloc;    //  The vector's allocator

    /* static_assert(std::is_same_v<_Ty, decltype(Allocator)::value_type>,
        "Types are not equivalent");*/

    /*---------------------------------*/
    /*----Constructors, Destructors----*/
    /*---------------------------------*/

    // constructs empty container
    Vector() : m_size(0), m_capacity(0) {
        m_data = m_alloc.allocate(m_capacity);
    }
    // constructs container with -count- elements of -value- value
    Vector(size count, const _Ty& value) {
        m_size = count;
        m_data = m_alloc.allocate(count); // allocate(m_capacity) ?
        std::fill_n(m_data, count, value); 
    }

    // Returns the container's allocator
    constexpr alty get_allocator() const {
        return m_alloc;
    }

    /*----------------------*/
    /*----ELEMENT ACCESS----*/
    /*----------------------*/

    // []
    constexpr _Ty& operator[](size index) const {
        return m_data[index];
    }

    /*-----------------*/
    /*----ITERATORS----*/
    /*-----------------*/

    /*----------------*/
    /*----CAPACITY----*/
    /*----------------*/

    /*-----------------*/
    /*----MODIFIERS----*/
    /*-----------------*/
};



#endif // VECTOR_HPP