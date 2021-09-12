// std::list Implementation by Théo R.
// 3rd September 2021 
// List.hpp
// Implemented as a Doubly-Linked List

/* REFERENCES:
* https://devdocs.io/cpp/container/list
* https://medium.com/@vgasparyan1995/how-to-write-an-stl-compatible-container-fc5b994462c6
* https://github.com/abulyaev/std-list-implementation
* https://arne-mertz.de/2018/03/forward-declaring-templates-and-enums/
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
#include <limits> // for numeric_limits 

// LIST_ITERATOR FORWARD DECLARATION
template <class Type>
class List_Iterator;

//	NODE CLASS
template <class Type>
class Node {
public:
	Type m_data;
	Node<Type>* m_previous;
	Node<Type>* m_next;

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

// LIST CLASS
template <class Type, class Allocator = std::allocator<Type>>
class List {
public: // Everything in public for aggregate-type ? 
	using reference				= Type&;
	using const_reference		= const Type&;
	using pointer				= Type*;
	using const_pointer			= const Type*;
	using alty					= std::allocator<Type>;
	using sz					= std::size_t;
	using difference_type		= std::ptrdiff_t;
	using it					= List_Iterator<Type>;		
	using const_it				= const List_Iterator<Type>;	
	using rev_it				= std::reverse_iterator<it>;	
	using const_rev_it			= std::reverse_iterator<const_it>;	

	//	We need at least the first and last nodes to operate
	//	on the container.
	Node<Type>* m_first;
	Node<Type>* m_last;

	std::size_t _size;
	std::size_t _maxsize;
	std::allocator<Type> _alloc;

	/* ---CTOR, DTOR, MCTOR, ALLOCATOR...--- */
	~List() {
		delete m_first; // Done in Node class ? ? ?
		delete m_last;
	}

	//	CTOR - Default, empty container
	explicit List() : _size(0), _maxsize(0) {
		m_first = new Node<Type>;
		m_last = new Node<Type>;
	}

	//	CTOR - Creates a list with count elements of value
	List(sz count, const Type& value) {}

	//	Returns associated allocator
	constexpr alty getAllocator() const {
		return _alloc;
	}

	/* ---ITERATORS--- */
	constexpr List_Iterator<Type> begin() const {}
	constexpr List_Iterator<Type> end() const {}

	/* ---CAPACITY--- */
	//size()
	constexpr sz max_size() const noexcept {
		// not sure about this one
		return std::numeric_limits<difference_type>::max();
	}
	//empty()

	/* ---ELEMENT ACCESS--- */
	void push_back(Type value) noexcept {
		
	}

	Type front() {
		return m_first->getData();
	}
	Type back() {
		return m_last->getData();
	}
};

template <class Type>
class List_Iterator : public List<Type> {

};

#endif //LIST_HPP