// std::vector Implementation by Théo R.
// 24th August 2021 
// Vector.hpp
// I won't be implementing all constant versions of member functions.

/* REFERENCES:
* https://devdocs.io/cpp/container/vector
* https://gcc.gnu.org/onlinedocs/gcc-4.8.0/libstdc++/api/a01638_source.html
* https://en.cppreference.com/w/cpp/container/vector
* https://www.tutorialspoint.com/cpp_standard_library/vector.htm
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
*/

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cassert>          // assert()
#include <algorithm>        // lexicographical_compare() 
#include <iostream> 
#include <memory>			// Allocators

#endif // VECTOR_HPP