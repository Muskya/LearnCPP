// std::list Implementation by Théo R.
// 3rd September 2021 (procrasti-man)
// List.hpp
// Implemented as a Doubly-Linked List

/* REFERENCES:
* https://devdocs.io/cpp/container/list
* https://medium.com/@vgasparyan1995/how-to-write-an-stl-compatible-container-fc5b994462c6
* https://github.com/abulyaev/std-list-implementation
* https://arne-mertz.de/2018/03/forward-declaring-templates-and-enums/
* https://www.geeksforgeeks.org/doubly-linked-list/
*/

/* Concepts learnt while writing this :
*	typedef vs
*	using:		(AKA alias-declaration) "using" is available since C++11. wont
*				detail why here, but always prioritize using over typedef. the 
*				best argument is that they are templatized, we can make 
*				generic aliases.
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
	Type data;
	Node<Type>* next;
	Node<Type>* previous;

	Node() : previous(nullptr), next(nullptr) {}
	Node(const Type data) : data(data), previous(nullptr),
		next(nullptr) {}

	constexpr Type getData() const {
		return data;
	}
	constexpr Node<Type>* getPrevious() const {
		if (previous != nullptr)
			return previous;
		else
			return nullptr;
	}
	constexpr Node<Type>* getNext() const {
		if (next != nullptr)
			return next;
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
	Node<Type>* head = nullptr;
	Node<Type>* tail = nullptr;

	std::size_t _size;
	std::size_t _maxsize = std::numeric_limits<difference_type>::max();
	std::allocator<Type> _alloc;

	/* ---CTOR, DTOR, MCTOR, ALLOCATOR...--- */
	~List() {
		delete head;
		delete tail;
	}

	//	CTOR - Default, empty container
	List() : _size(0), _maxsize(0) {}

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
	constexpr sz size() const noexcept {
		return _size;
	}
	constexpr sz max_size() const noexcept {
		// not sure about this one
		return _maxsize;
	}
	//empty()

	/* ---ELEMENT ACCESS--- */
	void push_front(Type value) noexcept {
		Node<Type>* node = new Node<Type>(value); 
		//std::cout << "in push_front()" << std::endl;
		//std::cout << "&node: " << &node << std::endl;
		//std::cout << "&head: " << &head << std::endl;
		//std::cout << "&tail: " << &tail << std::endl;
		//std::cout << "\n";
		
		// if push_front is the first insertion operation used,
		// head == tail;
		if (head == nullptr) {
			head = node;
			tail = head;
			// ALWAYS MENTION PREVIOUS/NEXT = NULLPTR FOR
			//					  HEAD/TAIL
			// COSTS NOTHING, ITS SAFER
			head->next = tail;
			head->previous = nullptr;
			tail->next = nullptr;
			tail->previous = head;
			++_size;
		}
		else { // after list is initialized
			node->next = head;
			head = node;
			head->previous = nullptr;
			++_size;
		}
	}

	void push_back(Type value) noexcept {
		Node<Type>* node = new Node<Type>(value);
		Node<Type>* last = head; // used to traverse later

		// if push_back is the first insertion operation used,
		// head == tail;
		if (head == nullptr) {
			head = node;
			tail = head;
			head->next = tail;
			head->previous = nullptr;
			tail->next = nullptr;
			tail->previous = head;
			++_size;
		}
		else { // after list is initialized
			// traverse to the end of the list to get the last node
			// used for operations
			while (last->next != nullptr) { // last == head on first iteration
				last->next = last;
			}

			// make sure the added node's previous node is
			// the old last one to make the new one the actual old one
			// OK ? my english is terrible
			node->previous = last;
			last = node;
		}
	}

	Type front() {
		return head->getData();
	}
	Type back() {
		return tail->getData();
	}

	/* ---MISCELLANEOUS--- */
	//debug purposes, not the final implementation
	//its absolute garbage lol i can feel it
	void display() {
		Node<Type>* traverse = head;
		if (head->next == tail) {
			std::cout << head->data << std::endl;
		}
		else {
			while (traverse->next != tail) {
				std::cout << traverse->data << std::endl;
				traverse = traverse->next;
			}
		}
		
	}
};


#endif //LIST_HPP