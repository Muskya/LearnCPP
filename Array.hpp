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
*   noexcept:       compile-time check operator that returns true if an expression
*                   has a "noexcept" specifier in its declaration.
*/

#ifndef ARRAY_HPP
#define ARRAY_HPP

// no clue what it does but it was in array.h source files
// so i decided to use it ¯\_(-_-)_/¯
#if _STL_COMPILER_PREPROCESSOR 
#include <cassert>

_STD_BEGIN // namespace std { 
template <class _Ty, _STD size_t _Size>
class Array
{
private:
    _STD size_t m_size; // _STD = ::std::
    _Ty* m_data;
public:
    using value_type        = _Ty;
    using pointer           = _Ty*;
    using reference         = _Ty&;
    using size_type         = _STD size_t;
    using iterator          = value_type*;
    using const_iterator    = const value_type*;

    ~Array() {
        delete[] m_data;
    }
    Array() {
        assert(_Size > 0 && "array has no size");
        m_data = new _Ty[_Size];
        m_size = _Size;
    }

    Array(const Array&) = delete; // To change
    Array& operator=(const Array&) = delete; // To change

    // ELEMENT ACCESS
    void erase() noexcept;
    constexpr _Ty* data();
    constexpr _Ty& operator[](int index);
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

// erases array whole content
TEMPLATE
void ARRAY::erase() noexcept {
    delete[] m_data;
    m_data = nullptr;
    m_size = 0;
}

// returns underlying C-Array
TEMPLATE
constexpr _Ty* ARRAY::data() {
    return m_data;
}

// []
TEMPLATE
constexpr _Ty& ARRAY::operator[](int index) {
    assert(index >= 0 && index < m_size && "index out of bounds");
    return m_data[index];
}

// returns array's length
TEMPLATE
constexpr _STD size_t ARRAY::size() const noexcept
{ return m_size; }

// returns array's maximum length
TEMPLATE
constexpr _STD size_t ARRAY::max_size() const noexcept
{ return std::size_t(); }

// returns true if array is empty
TEMPLATE
constexpr bool ARRAY::empty() const noexcept
{ return (this->size() == 0); }

_STD_END // ^^^ (namespace std) }

#endif // _STL_COMPILER_PREPROCESSOR
#endif // ARRAY_HPP