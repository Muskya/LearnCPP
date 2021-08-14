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
	T* _data;
	int _length;
	Storage _storage;
public:
	~MultiContainer() = default;
	MultiContainer() = default;
	MultiContainer(Storage type, int length);

	// DATA MANIPULATION
	bool add_back(T val);
	bool remove_back();

	// DATA 
	int length() const; // Used for Arrays
	int size() const; 
};

// Main MultiContainer constructor
template <class T>
MultiContainer<T>::MultiContainer(Storage type, int length)
	: _storage(type), _length(length)
{
	switch (_storage) {
	case ARR: // Arrays can't have a length of 0
		assert(length > 0);
		break;
	default:
		assert(length >= 0);
		break;
	}
	
	_data = new T[length];
}

// Adds a new element at the end of the container
template <class T>
bool MultiContainer<T>::add_back(T val) {
	
}

// Returns the length of the container (arrays exclusively)
template <class T>
int MultiContainer<T>::length() const {
	// Make sure it's an array
	// Length() method makes no sense for other containers
	assert(_storage == ARR); 
	return _length;
}

// Returns the size (number of elements) of the container
template <class T>
int MultiContainer<T>::size() const {

}
#endif