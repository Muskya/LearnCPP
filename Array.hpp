// std::array Implementation by Théo R.
// 18th August 2021
// Array.hpp
/* references : 
*
* https://devdocs.io/cpp/container/array
* https://gcc.gnu.org/onlinedocs/gcc-4.6.3/libstdc++/api/a00752_source.html
* https://en.cppreference.com/w/cpp/container/array
*/

// Details learnt about some of the concepts introduced in this .hpp :
/*  constexpr:      value/return value is constant and evaluated at compile-time.
*                   can be used whenever const value is needed, in templates 
*                   or array declarations for example.
*   noexcept:       compile-time check operator that returns true if an member func
*                   has a "noexcept" specifier in its declaration. For the member,
*                   noexcept means it will throw no exception.
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

    // size of the array. use size() or max_size() instead
    _STD size_t m_size = _Size; // _STD = ::std::
    // underlying c-array. use data() to access it instead
    _Ty m_data[_Size];

    Array() = default;
    inline Array(std::initializer_list<_Ty> list) noexcept {
        for (int i = 0; i < _Size; i++) {
            m_data[i] = *(list.begin() + i);
        }
    }
    Array(const Array&) = delete; // To change
    Array& operator=(const Array&) = delete; // To change

    // ELEMENT ACCESS
    constexpr _Ty* data();
    constexpr _Ty& operator[](size_type index);
    constexpr void fill();
    constexpr void swap();
    //front, back

    // CAPACITY
    constexpr std::size_t size() const noexcept;
    constexpr std::size_t max_size() const noexcept;
    constexpr bool empty() const noexcept;

    // ITERATORS
    constexpr iterator begin() noexcept;
    constexpr iterator end() noexcept;
    // cbegin, cend, rbegin, rend, crbegin, crend..........
};

// some writing shortcuts
#define TEMPLATE template <class _Ty, _STD size_t _Size>
#define ARRAY Array<_Ty, _Size> 

/*----ELEMENT ACCESS----*/
// returns underlying C-Array
TEMPLATE
constexpr _Ty* ARRAY::data() {
    return m_data;
}

// []
TEMPLATE
constexpr _Ty& ARRAY::operator[](_STD size_t index) {
    assert(index >= 0 && index < _Size && "index out of bounds");
    return m_data[index];
}

/*----CAPACITY----*/
// returns array's length
TEMPLATE
constexpr _STD size_t ARRAY::size() const noexcept
{ return _Size; }

// returns array's maximum length
TEMPLATE
constexpr _STD size_t ARRAY::max_size() const noexcept
{ return _Size; }

// returns true if array is empty
TEMPLATE
constexpr bool ARRAY::empty() const noexcept
{ return (this->size() == 0); }

/*----ITERATORS----*/
// iterator at the beginning of the array
TEMPLATE
constexpr _Ty* ARRAY::begin() noexcept {
    return &m_data[0];
}

TEMPLATE
constexpr _Ty* ARRAY::end() noexcept {
    return &m_data[_Size - 1];
}

#endif // _STL_COMPILER_PREPROCESSOR
#endif // ARRAY_HPP