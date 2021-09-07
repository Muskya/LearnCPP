// std::list Implementation by Théo R.
// 3rd September 2021 
// List.hpp
// Implemented as a Doubly-Linked List

/* REFERENCES:
* https://devdocs.io/cpp/container/list
* https://medium.com/@vgasparyan1995/how-to-write-an-stl-compatible-container-fc5b994462c6
* https://github.com/abulyaev/std-list-implementation
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

#ifndef LIST_HPP
#define LIST_HPP

#include <cassert>
#include <algorithm>
#include <iostream>

//	NODE CLASS
template <class Type>
class Node {
private:
	Type m_data;
	Node<Type>* m_previous;
	Node<Type>* m_next;
public:
	Node() : m_previous(nullptr), m_next(nullptr) {}
	Node(const Type data) : m_data(data), m_previous(nullptr),
		m_next(nullptr) {}

	constexpr Type getData() const {
		return m_data;
	}
	constexpr Node<Type>* getPrevious() const {
		if (m_previous != nullptr)
			return m_previous;
		else
			return nullptr;
	}
	constexpr Node<Type>* getNext() const {
		if (m_next != nullptr)
			return m_next;
		else
			return nullptr;
	}
};

// LIST_ITERATOR CLASS
template <class Type>
class List_Iterator {
private:
public:
};

// LIST CLASS
template <class Type, class Allocator = std::allocator<Type>>
class List {
private:
	//	We need at least the first and last nodes to operate
	//	on the container.
	Node<Type>* m_first;
	Node<Type>* m_last;

public:
	using reference				= Type&;
	using const_reference		= const Type&;
	using pointer				= Type*;
	using const_pointer			= const Type*;
	using alty					= std::allocator<Type>;
	using sz					= std::size_t;
	using it					= pointer;							// ?
	using const_it				= const pointer;					// ?
	using rev_it				= std::reverse_iterator<it>;		// ?
	using const_rev_it			= std::reverse_iterator<const_it>;	// ?

	sz _size;
	sz _maxsize;
	alty _alloc;

	/* ---CTOR, DTOR, MCTOR, ALLOCATOR...--- */
	//	CTOR - Default, empty container
	explicit List() : _size(0), _maxsize(0) {
		m_first->m_previous = nullptr;
		m_last->m_next = nullptr;
		m_first->m_next = m_last;
		m_last->m_previous = m_first;
	}

	//	CTOR - Creates a list with count elements of value
	List(sz count, const Type& value) {}

	//	Returns associated allocator
	constexpr alty getAllocator() const {
		return _alloc;
	}

	/* ---ITERATORS--- */
	constexpr it begin() const {}
	constexpr it end() const {}

	/* ---CAPACITY--- */
	//size()
	//maxsize()
	//empty()
	
};

#endif //LIST_HPP