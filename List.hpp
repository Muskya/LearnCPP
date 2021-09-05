// std::list Implementation by Théo R.
// 3rd September 2021 
// List.hpp
// Implemented as a Doubly-Linked List. (pointers to previous and next
// nodes)

/* REFERENCES:
* 
* MSVC's list source file (C:\Program Files (x86)\Microsoft Visual Studio\2019\
  Community\VC\Tools\MSVC\14.28.29910\include\list)
*/

/* Concepts learnt while writing this :
*	typedef vs
*	using:		(AKA alias-declaration) "using" is available since C++11. wont
*				detail why here, but always prioritize using over typedef. the 
*				best argument is that they are templatized, we can make 
*				generic aliases.
*	
* 
*/

template <class Type, class Allocator = std::allocator<Type>>
class List {
	
	using reference				= Type&;
	using const_reference		= const Type&;
	using pointer				= Type*;
	using const_pointer			= const Type*;
	using s_type				= std::size_t;

	struct Node {
		Type data;
		Node* next;
		Node* prev;
	};

};