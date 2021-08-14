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
	T* _data;
	int _length;
	Storage _storage;
public:
	// CONSTRUCTORS DESTRUCTORS
	~MultiContainer() = default;
	MultiContainer() = default;
	MultiContainer(Storage type, int length = 0);

	// DATA MANIPULATION
	bool add_back(T val);
	bool remove_back();
	// begin(), end() [allocators?]

	// DATA DATA
	int length() const; // Arrays Exclusively
	int size() const; 

	// OPERATORS
	T& operator[](int index);
	T& operator=(T& const mc) = delete; // No instance copying (for now)
};

// Main MultiContainer constructor
// Don't add a length in the case of anything but an array
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
	assert(_storage == ARR && "Container is not an array."); 
	return _length;
}

// Returns the size (number of elements) of the container
template <class T>
int MultiContainer<T>::size() const {
	int size = 0;
	T* elemPtr = nullptr;
	if (_storage == ARR) {
		if (this->length() == 0)
			return 0;
		assert(this->length() > 0);
		// Logic is : if our pointer elemPtr who's pointing to the
		// &_data[i] element is nullptr, it means there are no more elements
		// in the array
		for (int i = 0; i < this->length(); i++) {
			elemPtr = &_data[i];
			if (elemPtr == nullptr) {}
			else { size++; }
		}
	}
	else { // Other containers have dynamic length
		int n = 0;
		if (&_data[n] == nullptr) // If there are no elements yet
			return 0;
		else {
			while (n < INT_MAX) { // I feel like this is bad practice kek
				n++;
				if (&_data[n] != nullptr) {
					elemPtr = &_data[n];
					size++;
				}
				else { break; }
			}
		}
	}
	return size;
}

template <class T>
T& MultiContainer<T>::operator[](int index) {
	// If we are operating on an array and thus with
	// fixed-length
	if (_storage == ARR) {	
		assert(index >= 0 && index < _length && "Index out of bounds.");
		return _data[index];
	}
	// If we are operating on any other container type
	else {
		// Simply increment container length and return
		// the data at the specified index
		_length++;
		return _data[index];
	}
}
#endif