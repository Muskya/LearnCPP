// std::list (Doubly-Linked) Implementation by Théo R.
// 3rd September 2021 (procrasti-man) (back at it again)
// List.hpp

/* REFERENCES:
* https://devdocs.io/cpp/container/list
* https://medium.com/@vgasparyan1995/how-to-write-an-stl-compatible-container-fc5b994462c6
* https://github.com/abulyaev/std-list-implementation
* https://arne-mertz.de/2018/03/forward-declaring-templates-and-enums/
* https://www.geeksforgeeks.org/doubly-linked-list/
* https://www.geeksforgeeks.org/implementing-iterator-pattern-of-a-single-linked-list/
*/

/* Concepts learnt while writing this :
*	typedef vs
*	using:		(AKA alias-declaration) "using" is available since C++11. wont
*				detail why here, but always prioritize using over typedef. the 
*				best argument is that they are templatized, we can make 
*				generic aliases.
* 
*	range-based
*	for loops:	in order to be used, range-based loop require the container/
*				sequence/range they operate on to have a begin() and end() 
*				function definition. these usually return iterator, which 
*				usually need to overload operators ++, --, !=, ==, and *.
*				also range-based for loops dont work on pointer types.
*/

/* TO-DO LIST LIST
* all remaining operation/modifier functions listed at : 
* https://devdocs.io/cpp/container/list
*/

#ifndef LIST_HPP
#define LIST_HPP

#include <cassert>
#include <algorithm>
#include <iostream>
#include <limits>

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
		assert(this != nullptr && "trying to get data from null node");
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

// LIST CUSTOM ITERATOR
template <class Type>
class List_Iterator {
public:
	// The current node pointed by the iterator
	Node<Type>* current;

	List_Iterator() = default;
	List_Iterator(Node<Type>* start) {
		current = start;
	}

	inline const Type operator*() {
		return current->getData();
	}
	virtual inline List_Iterator* operator++() {
		assert(current != nullptr && "cant operate on nullptr node");
		current = current->next;
		return this;
	}
	virtual inline List_Iterator* operator++(int) {
		assert(current != nullptr && "cant operate on nullptr node");
		current = current->next;
		return this;
	}
	virtual inline List_Iterator* operator--() {
		assert(current != nullptr && "cant operate on nullptr node");
		assert(current->previous != nullptr &&
			"cant decrement iterator if previous node is null");
		current = current->previous;
		return this;
	}
	virtual inline List_Iterator* operator--(int) {
		assert(current != nullptr && "cant operate on nullptr node");
		assert(current->previous != nullptr &&
			"cant decrement iterator if previous node is null");
		current = current->previous;
		return this;
	}
	inline bool operator!=(const List_Iterator<Type>& rhs) {
		//Dont need an assert here because in for{} statements, when we use
		//"it != list->end()", it returns the next node pointed by the tail, which
		//is a null pointer. keeping the assert would raise an abort() call.
		//so for this operator we just return with no checks.

		//assert(current != nullptr && "cant operate on nullptr node");
		return current != rhs.current;
	}
	inline bool operator==(const List_Iterator<Type>& rhs) {
		return current == rhs.current;
	}
};

// works on List_R_Iterator too since it inherits from List_Iterator
template <class Type>
std::ostream& operator<<(std::ostream& out, const List_Iterator<Type>& rhs) {
	out << rhs.current;
	return out;
}

template <class Type>
class List_R_Iterator : public List_Iterator<Type> {
public:
	List_R_Iterator(Node<Type>* start) {
		this->current = start; // tail (nullptr)
	}

	virtual inline List_R_Iterator* operator++() {
		assert(this->current != nullptr && "cant operate on nullptr node");
		this->current = this->current->previous;
		return this;
	}
	virtual inline List_R_Iterator* operator++(int) {
		assert(this->current != nullptr && "cant operate on nullptr node");
		this->current = this->current->previous;
		return this;
	}
	virtual inline List_R_Iterator* operator--() {
		assert(this->current != nullptr && "cant operate on nullptr node");
		assert(this->current->next != nullptr &&
			"cant decrement iterator if next node is null");
		this->current = this->current->next;
		return this;
	}
	virtual inline List_R_Iterator* operator--(int) {
		assert(this->current != nullptr && "cant operate on nullptr node");
		assert(this->current->next != nullptr &&
			"cant decrement iterator if next node is null");
		this->current = this->current->next;
		return this;
	}
};

// LIST CLASS
template <class Type, class Allocator = std::allocator<Type>>
class List {
public: // Everything in public for aggregate-type ? 
	using reference				= Type&;
	using pointer				= Type*;
	using alty					= std::allocator<Type>;
	using sz					= std::size_t;
	using iterator				= List_Iterator<Type>;
	using const_iterator		= const List_Iterator<Type>;
	using reverse_iterator		= List_R_Iterator<Type>;
		
	//	We need at least the first and last nodes to operate
	//	on the list.
	Node<Type>* head;
	Node<Type>* tail;

	std::size_t _size;
	std::size_t _maxsize;
	std::allocator<Type> _alloc;

	/* ---CTOR, DTOR, MCTOR, ALLOCATOR...--- */
	~List() {
		delete head;
		delete tail;
	}

	//	CTOR - Default, empty container
	List() : _size(0), _maxsize(0) {}

	//	CTOR - Creates a list with count elements of value
	List(sz count, const Type& value) 
		: _size(count), _maxsize(0) // _maxsize needs to change
	{
		std::vector<Node<Type>*> nodeVec(count);

		if (count == 1) {
			this->push_front(value);
		}
		else if (count == 2) {
			this->push_front(value);
			this->push_back(value);
		}
		else {
			//Initialize head and tail
			head = new Node<Type>(value);
			tail = new Node<Type>(value);

			// fill a vector with count nodes to make
			// operations easier
			for (int i = 0; i < count; i++) {
				if (i == 0) 
					nodeVec[i] = head;
				else if (i == count - 1) 
					nodeVec[i] = tail;
				else 
					nodeVec[i] = new Node<Type>(value);
			}

			// now link all the nodes (prev/next)
			// have C26451 arithmetic overflow warning on indexes:
			// "Using operator '+' on a 4 byte value and then
			// casting the result to a 8 byte value."
			// its apparently a bug. im only operating on indexes here.
			for (int i = 0; i < count - 1; i++) {
				nodeVec[i]->next = nodeVec[i + 1];
				nodeVec[i + 1]->previous = nodeVec[i];
			}
		}
	}

	// CTOR - Creates a list from a braced{} value list
	List(std::initializer_list<Type> i_list) {}

	//	Returns associated allocator
	constexpr alty getAllocator() const {
		return _alloc;
	}

	/* ---ITERATORS--- */
	// just return head and tail. logic is done within
	// the List_Iterator class template.
	constexpr iterator begin() noexcept {
		return List_Iterator<Type>(head);
	}
	constexpr iterator end() noexcept  {
		// end() functions always return past-the-last "element"
		return List_Iterator<Type>(tail->next);
	}
	constexpr reverse_iterator rbegin() {
		return List_R_Iterator<Type>(tail);
	}
	constexpr reverse_iterator rend() {
		// rend returns end of REVERSE (mirrored) list sequence
		// thus it is past the last element which is head's previous node (nullptr)
		return List_R_Iterator<Type>(head->previous);
	}

	/* ---CAPACITY--- */
	constexpr sz size() const noexcept {
		return _size;
	}
	constexpr sz maxsize() const noexcept {
		// really not sure this is the right way of returning the
		// max size of a list container. here we just return the max size
		// of a general allocator of type <Type>... can't find any help
		// on the internet.
		return _alloc.max_size();
	}
	constexpr bool empty() const noexcept {
		return (_size == 0);
	}

	/* ---ELEMENT_ACCESS--- */
	void push_front(Type value) noexcept {
		Node<Type>* node = new Node<Type>(value); 
		
		// if push_front is the first insertion operation used,
		// head == tail;
		if (head == nullptr) {
			head = node;
			tail = head;
			// ALWAYS MENTION PREVIOUS/NEXT = NULLPTR FOR
			//					  HEAD/TAIL
			// COSTS NOTHING AND ITS SAFER
			head->next = tail;
			head->previous = nullptr;
			tail->next = nullptr;
			tail->previous = head;

			++_size;
		}
		else { // after list is initialized
			node->next = head;
			node->previous = nullptr; // new head
			head->previous = node;
			head = node;
			
			++_size;
		}
	}
	void push_back(Type value) noexcept {
		Node<Type>* node = new Node<Type>(value);

		if (head == nullptr) {
			head = node;
			node->previous = nullptr;
			node->next = nullptr;
			tail = node;

			++_size;
		}
		else { // after list is initialized
			node->previous = tail;
			tail->next = node;
			node->next = nullptr;
			tail = node;

			++_size;
		}
	}
	void clear() {
		assert(!empty() && "cannot clear an empty list");
		Node<Type>* current = head;
		Node<Type>* next = nullptr; //temp

		while (current != nullptr) {
			next = current->next;
			delete current;
			current = next;
		}

		head = nullptr;
		_size = 0;
	}

	/* different overloads for inserting an 
	element somewhere in the list */

	// inserts a new node before given iterator position
	iterator insert(iterator pos, const Type& value) {
		Node<Type> node = new Node<Type>(value);

	}

	Type front() {
		return head->getData();
	}
	Type back() {
		return tail->getData();
	}

	/* ---OPERATIONS--- */

	/* ---MISCELLANEOUS--- */
	void print()
	{
		if (empty()) {
			std::cout << "List is null." << std::endl;
		}
		else {
			Node<Type>* temp = head;
			while (temp != nullptr)
			{
				std::cout << temp->getData() << " ";
				temp = temp->next;
			}
			std::cout << "\n";
		}
		
	}
};

#endif //LIST_HPP