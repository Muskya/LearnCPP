// std::vector Implementation by Théo R.
// 24th August 2021
// Vector.hpp
// I won't be implementing all the 
// constant versions of member functions.
/* references :
*
* https://devdocs.io/cpp/container/vector
* https://gcc.gnu.org/onlinedocs/gcc-4.8.0/libstdc++/api/a01638_source.html
* https://en.cppreference.com/w/cpp/container/vector
* <vector> from c++14
*/

// Details learnt while writing this implementation :
/*  xxxxxxxxx:      yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy.
*                   uuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuu
*/

#ifndef VECTOR_HPP
#define VECTOR_HPP

#if _STL_COMPILER_PREPROCESSOR 
#include <cassert>          // assert()
#include <algorithm>        // lexicographical_compare() 
#include <iostream>         // << (>>?) operator overloading (ostream/istream)

#endif // __STL_COMPILER_PREPROCESSOR_
#endif // VECTOR_HPP