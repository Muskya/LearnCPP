// std::array Implementation by Théo R.
// 18th August 2021
// Array.hpp
// This is just practice. I won't be implementing all the 
// constant versions of member functions. (or later kek)
/* references : 
*
* https://devdocs.io/cpp/container/array
* https://gcc.gnu.org/onlinedocs/gcc-4.6.3/libstdc++/api/a00752_source.html
* https://en.cppreference.com/w/cpp/container/array
*/

// Details learnt while writing this implementation :
/*  constexpr:      value/return value is constant and evaluated at compile-time.
*                   can be used whenever const value is needed, in templates 
*                   or array declarations for example. ("const" after function declaration
*                   means that fields are not affected)
*   noexcept:       compile-time check operator that returns true if an member func
*                   has a "noexcept" specifier in its declaration. For the member,
*                   noexcept means it will throw no exception.
*   POD:            "Plain Old Data". Class/Struct without any (virtual)functions,
*                   constructor, or destructor. 
*   Aggregate:      An aggregate is an array or a class with no user-declared 
                    constructors, no private or protected non-static data members,
                    no base classes, and no virtual functions.
*/

#ifndef ARRAY_HPP
#define ARRAY_HPP

// no clue what it does but it was in array.h source files
// so i decided to use it ¯\_(-_-)_/¯
#if _STL_COMPILER_PREPROCESSOR 
#include <cassert>

template <class _Ty, _STD size_t _Size>
class Array 
{
public:
    using value_type        = _Ty;
    using pointer           = _Ty*;
    using reference         = _Ty&;
    using size_type         = _STD size_t;
    using iterator          = pointer;
    using const_iterator    = const pointer;
    using reverse_iterator  = _STD reverse_iterator<iterator>;

    // size of the array. use size() or max_size() instead. same reason
    // as with m_data[]
    _STD size_t m_size = _Size; // ::std::
    // underlying c-array. use data() to access it instead. has to be
    // public to make Array an aggregate-type
    _Ty m_data[_Size];

    Array() = default;
    inline Array(std::initializer_list<_Ty> list) noexcept {
        for (int i = 0; i < _Size; i++) {
            m_data[i] = *(list.begin() + i);
        }
    }
    Array(const Array&) = delete; // To change
    Array& operator=(const Array&) = delete; // To change

    // ELEMENT ACCESS/MANIPULATION
    constexpr _Ty* data() noexcept;
    const _Ty* data() const noexcept;
    void fill(_Ty value, int beg = 0, int end = _Size-1);
    constexpr void swap(Array<_Ty, _Size>& other) noexcept;
    constexpr _Ty front() const noexcept;
    constexpr _Ty back() const noexcept;
    constexpr _Ty at(_STD size_t index) const noexcept;
    constexpr _Ty& operator[](size_type index);

    // CAPACITY
    constexpr std::size_t size() const noexcept;
    constexpr std::size_t max_size() const noexcept;
    constexpr bool empty() const noexcept;

    // ITERATORS
    constexpr iterator begin() noexcept;
    constexpr iterator end() noexcept;
    constexpr std::reverse_iterator<_Ty*> rbegin() noexcept;
    constexpr std::reverse_iterator<_Ty*> rend() noexcept;

    // MISC
    void show() {
        std::cout << "\n";
        for (int i = 0; i < _Size; i++) {
            if (i == _Size - 1)
                std::cout << m_data[i];
            else
                std::cout << m_data[i] << ", ";
        }
    }
};

/*----ELEMENT ACCESS----*/
// returns underlying c-array
template <class _Ty, _STD size_t _Size>
constexpr _Ty* Array<_Ty, _Size>::data() noexcept {
    return m_data;
}

// returns underlying const c-array
template <class _Ty, _STD size_t _Size>
const _Ty* Array<_Ty, _Size>::data() const noexcept {
    return m_data;
}
// fills the array with the specified value. whole array
// is filled if indexs are not specified.
template <class _Ty, _STD size_t _Size>
void Array<_Ty, _Size>::fill(_Ty value, int beg, int end) {
    for (int i = beg; i <= end; i++) {
        m_data[i] = value;
    }
}
// swaps the arrays elements
template <class _Ty, _STD size_t _Size>
constexpr void Array<_Ty, _Size>::swap(Array<_Ty, _Size>& other) noexcept {
    assert(size() == other.size() && "arrays are not the same size");
    Array<_Ty, _Size>* tmp = new Array<_Ty, _Size>();
    tmp->fill(0);
    for (int i = 0; i < _Size; i++) {
        (*tmp)[i] = m_data[i];
        m_data[i] = other[i];
        other[i] = (*tmp)[i];
    }
    delete tmp;
}
// returns the first item of the array
template <class _Ty, _STD size_t _Size>
constexpr _Ty Array<_Ty, _Size>::front() const noexcept {
    return *begin();
}
// returns the last item of the array
template <class _Ty, _STD size_t _Size>
constexpr _Ty Array<_Ty, _Size>::back() const noexcept {
    return *end();
}
// returns the item at the specified index
// features bounds checking.
template <class _Ty, _STD size_t _Size>
constexpr _Ty Array<_Ty, _Size>::at(_STD size_t index) const noexcept {
    assert(index >= 0 && index < _Size && "index ouf of bounds");
    return m_data[index];
}

// [] overload. for bounds checking, use at()
template<class _Ty, std::size_t _Size>
constexpr _Ty& Array<_Ty, _Size>::operator[](size_type index)
{
    return m_data[index];
}

/*----CAPACITY----*/
// returns array's length
template <class _Ty, _STD size_t _Size>
constexpr _STD size_t Array<_Ty, _Size>::size() const noexcept
{ return _Size; }

// returns array's maximum length
template <class _Ty, _STD size_t _Size>
constexpr _STD size_t Array<_Ty, _Size>::max_size() const noexcept
{ return _Size; }

// returns true if array is empty
template <class _Ty, _STD size_t _Size>
constexpr bool Array<_Ty, _Size>::empty() const noexcept
{ return (this->size() == 0); }

/*----ITERATORS----*/
// iterator pointing at the first array's element address
template <class _Ty, _STD size_t _Size>
constexpr _Ty* Array<_Ty, _Size>::begin() noexcept {
    return &m_data[0];
}

// iterator pointing at the past-the-last element address
template <class _Ty, _STD size_t _Size>
constexpr _Ty* Array<_Ty, _Size>::end() noexcept {
    return &m_data[_Size]; // Past-the-end element
}

// reverse_iterator pointing at the first element adress of the 
// reversed sequence (end of normal sequence)
template <class _Ty, _STD size_t _Size>
constexpr _STD reverse_iterator<_Ty*> Array<_Ty, _Size>::rbegin() noexcept {
    return _STD reverse_iterator<_Ty*>(end());
}

// reverse_iterator pointing at the past-the-last element adress of 
// the reversed sequence
template <class _Ty, _STD size_t _Size>
constexpr _STD reverse_iterator<_Ty*> Array<_Ty, _Size>::rend() noexcept {
    return _STD reverse_iterator<_Ty*>(begin());
}

#endif // _STL_COMPILER_PREPROCESSOR
#endif // ARRAY_HPP


