// std::vector Implementation by Th?o R.
// 24th August 2021 
// Vector.hpp
// Won't be implementing all const / other overloads except for
// "crucial" ones

/* REFERENCES:
* https://devdocs.io/cpp/container/vector
* https://gcc.gnu.org/onlinedocs/gcc-4.8.0/libstdc++/api/a01638_source.html
* https://en.cppreference.com/w/cpp/container/vector
* https://www.tutorialspoint.com/cpp_standard_library/vector.htm
* https://hadibrais.wordpress.com/2013/11/10/dissecting-the-c-stl-vector-part-1-introduction/
* MSVC's vector souce file (C:\Program Files (x86)\Microsoft Visual Studio\2019\
  Community\VC\Tools\MSVC\14.28.29910\include\vector)
*/

//  Concepts learnt while writing this :
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
*                   used instead of common integer types to keep various implementations
*                   safe.
*   explicit:       C++ keyword that specifies that a constructor with a single parameter
*                   (called a converting constructor), cannot be used for implicit conversion
*                   and copy-initialization. 
*                   https://stackoverflow.com/questions/121162/what-does-the-explicit-keyword-mean
*   variadic temp:  A variadic template is a template with at least one parameter pack.
*   parameter pack: A parameter pack takes the form "typename|class... Args". It's a parameter
*                   that accepts zero or more template arguments (non-types, types, templates)
*                   The parameter pack name doesn't have to be "Args" exclusively.
*   LValueRValue:   To make it simple, LValue have adresses, RValue don't. 6, 'v', true are r-values.
*                   int a is a l-value. "T&&" in function/template paremeters mean it only acceps
*                   r-values references, that are about to be destroyed.
*   
*/

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <algorithm>
#include <iostream> 
#include <memory>			// Allocators
#include <cassert>          // assert()

template <class _Ty, class Allocator = std::allocator<_Ty>>
class Vector {
public:
    using value_type                = _Ty;
    using pointer                   = _Ty*;
    using reference                 = _Ty&;
    using alty                      = std::allocator<_Ty>;
    using sz                        = std::size_t;
    using difference_type           = std::ptrdiff_t;   // Pointer arithmetic (long long)
    using iterator                  = pointer;
    using const_iterator            = const iterator;
    using reverse_iterator          = std::reverse_iterator<iterator>;

    // FIELDS
    sz m_size;                      //  Nb of elements (can't be more than capacity)
    sz m_capacity;                  //  Current allocated storage
    pointer m_data;                 //  Underlying C-Array
    alty m_alloc;                   //  Associated allocator

    /*---------------------------------*/
    /*----Constructors, Destructors----*/
    /*---------------------------------*/

    //  constructs empty container
    Vector() : m_size(0), m_capacity(0) {
        m_data = m_alloc.allocate(capacity()); // useless ?
    }
    //  constructs container with -count- elements of -value- value
    Vector(sz count, const _Ty& value) {
        m_size = count;
        m_capacity = m_size;
        m_data = m_alloc.allocate(capacity()); // reserve
        std::fill_n(m_data, count, value); 
    }

    //  replaces the content with count copies of value
    //  ( 2 more overloads )
    void assign(sz count, const _Ty& value) {
        clear();
        if (count > capacity()) {
            reserve(count);    
        }
        
        m_size = count;
        std::fill_n(m_data, count, value);
    }
    //  returns the container's allocator
    constexpr alty get_allocator() const {
        return m_alloc;
    }

    /*----------------------*/
    /*----ELEMENT ACCESS----*/
    /*----------------------*/

    //  returns underlying c-array
    _Ty* data() noexcept {
        return m_data;
    }
    //  returns element at specified position with bounds-checking
    _Ty& at(sz pos) {
        return m_data[pos];
    }
    //  []operator overload
    constexpr _Ty& operator[](sz index) const {
        assert(size() > 0 && "vector's size is zero. resize it first.");
        assert(index >= 0 && index < size() && "index out of bounds");
        return m_data[index];
    }
    //  returns first element
    _Ty& front() {
        assert(size() > 0 && "container is empty");
        return m_data[0];
    }
    //  returns last element
    _Ty& back() {
        assert(size() > 0 && "container is empty");
        return m_data[size() - 1];
    }

    /*-----------------*/
    /*----ITERATORS----*/
    /*-----------------*/

    //  returns iterator pointing to first element
    constexpr iterator begin() const {
        return &(m_data[0]);
    }
    //  returns iterator pointing to past-the-last element
    constexpr iterator end() const {
        return &(m_data[size()]);
    }
    // reverse_iterator pointing at the first element adress of the 
    // reversed sequence (last elemet of normal sequence)
    constexpr reverse_iterator rbegin() const {
        return reverse_iterator(end);
    }
    // reverse_iterator pointing at the past-the-last element adress of 
    // the reversed sequence  (first element of normal sequence)
    constexpr reverse_iterator rend() const {
        return reverse_iterator(begin());
    }

    // const versions ...

    /*----------------*/
    /*----CAPACITY----*/
    /*----------------*/

    //  returns true if container's size is 0 (no elements)
    constexpr bool empty() const {
        return size() == 0 ? true : false;
    }
    //  returns current number of elements 
    constexpr sz size() const {
        return m_size;
    }
    //  returns maximum number of elements allowed
    //  (container's allocator's max size)
    constexpr sz max_size() const {
        return get_allocator().max_size();
    }
    //  reserves storage (capacity) with associated allocator
    //  size is not affected here. make sure to modify it before/after
    //  function call.
    void reserve(sz new_cap) {
        //  static_assert only works with constexpr and const types. 
        //  (compile-time resolving)
        //  should probably use if-else statement instead of abort-call with assert ?
        assert(new_cap > m_capacity && "Invalid new capacity");
        m_capacity = new_cap;
        //  allocate() DOES NOT ADD storage. it OVERWRITES it.
        m_data = get_allocator().allocate(capacity());
    }
    //  returns number of elements that the container has 
    //  currently allocated storage for
    constexpr sz capacity() const {
        return m_capacity;
    }
    //  resizes the container.
    void resize(const sz& new_size) {
        assert(new_size > size() && !(new_size < size())
            && "new_size is invalid.");
        m_size = new_size;
        if (size() > capacity()) {
            reserve(capacity() + size());
        }
    }
    //  removes unused allocated memory/storage (capacity)
    void shrink_to_fit() {
        assert(capacity() > size() && "some allocated memory (capacity) has to be unused");
        for (sz i = size(); i < capacity(); i++) {
            get_allocator().destroy(m_data() + i);
        }
        m_capacity = size();
    }

    /*-----------------*/
    /*----MODIFIERS----*/
    /*-----------------*/

    //  erases all elements from the container. 
    //  capacity remains unchanged.
    void clear() {
        //  could use "delete[] m_data" here ?
        for (sz i = 0; i < size(); i++)
            get_allocator().destroy(m_data() + i);
        m_size = 0;
    }
    //  inserts value before pos, returns iterator pointed to inserted value
    iterator insert(iterator pos, _Ty const& value) {
        if (size() == capacity()) {
            m_capacity++;
            m_data = get_allocator().allocate(m_capacity + 1);
        }
        difference_type index = pos - begin();
        iterator it = &m_data[index];

        std::move(it, end(), it + 1);
        *it = value; // *it = std::move(value) ?

        ++m_size;
        return it;
    }
    //  adds element at the end of container
    void push_back(const _Ty& value) {
        if (size() == capacity()) {
            m_capacity++;
            m_data = get_allocator().allocate(m_capacity + 1);
        }

        get_allocator().construct(end()-1, value);
        ++m_size;
    }
    //  removes last element
    void pop_back() {
        get_allocator().destroy(end()-1);
        --m_size;
    }
    //  constructs element in-place (std::allocator_traits::construct) at pos
    template <class... Args>
    iterator emplace(const_iterator pos, Args&&... args) {
        if (size() == capacity()) {
            m_capacity++;
            m_data = get_allocator().allocate(m_capacity + 1);
        }
        difference_type index = pos - begin();
        iterator it = &m_data[index];

        std::move(it, end(), it + 1);
        get_allocator().construct(it, args...); // *it = std::move(value) ?

        ++m_size;
        return it;
    }
    //  constructs element in-place (std::allocator_traits::construct) at the end
    template< class... Args >
    void emplace_back(Args&&... args) {
        emplace(end(), std::forward<Args>(args)...);
    }
    // swap()
    // erase()
};



#endif // VECTOR_HPP