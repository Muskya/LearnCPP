#ifndef MULTICONTAINER_HPP
#define MULTICONTAINER_HPP

#include <cstdint>
#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>

// "MultiContainer.hpp" by Théo R.
// Date: 13/08/2021 (August 13th)
// Essentially a class to store any fundamental or user-defined data.
// The objective is to make a "all-in-one container" for Sequence Containers
// (std::array (not c-style array), vector, forward_list, list, deque).

enum class Storage { ARRAY, VECTOR, DEQUE };
// Forward list and List will be added later.

#define ARR Storage::ARRAY
#define VEC Storage::VECTOR
#define DEQ Storage::DEQUE

template <class T>
class MultiContainer
{
private:
	// FIELDS
	T*				_data;
	int				_size;
	int				_length;
	Storage			_storage;
public:
	// CONSTRUCTORS DESTRUCTORS
	~MultiContainer()			= default;
	MultiContainer()			= default;
	MultiContainer(Storage type, int length = 0);

	// DATA MANIPULATION
	void add_back(T val);
	void remove_back();
	// begin(), end() [allocators?]

	// DATA DATA
	int length() const;
	int size() const; 

	// OPERATORS
	T& operator[](int index);
	T& operator=(T& const mc)	= delete; // No instance copying (for now)
};

// Main MultiContainer constructor
// Don't add a length in the case of anything but an array
template <class T>
MultiContainer<T>::MultiContainer(Storage type, int length)
	: _storage(type), _size(0)
{
	switch (_storage) {
	case ARR: // Arrays can't have a length of 0
		assert(length > 0);
		this->_length = length;
		break;
	default:
		this->_length = INT_MAX;
		break;
	}
	_data = new T[length];
}

// Adds a new element at the end of the container
template <class T>
void MultiContainer<T>::add_back(T val) {
	assert(this->size() < this->length());
	if (this->size() == 0) {
		_data[0] = val; _size++;
	}
	else {
		 _data[this->size()] = val; 
		 _size++;
	}
}

// Returns the length of the container (arrays exclusively)
template <class T>
int MultiContainer<T>::length() const {
	return _length;
}

// Returns the size (number of elements) of the container
template <class T>
int MultiContainer<T>::size() const {
	return _size;
}

// Operator[] Overloading
template <class T>
T& MultiContainer<T>::operator[](int index) {
	if (_storage == ARR) 
		assert(index >= 0 && index < _length && "Index out bounds.");
	return _data[index];
}
#endif