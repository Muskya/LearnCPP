#ifndef MULTICONTAINER_HPP
#define MULTICONTAINER_HPP

#include <cstdint>
#include <iostream>
#include <string>
#include <algorithm>

// Essentially a class to store any fundamental or user-defined data.
// The goal is to make a "all-in-one container" with the likes of
// vector, queue, set, stack ... 
// I don't even know if that could be a thing but let's try.

template <class T, uint32_t size>
class MultiContainer
{
private:
	T* _data[size];
public:
	~MultiContainer() = default;
	MultiContainer() = default;

};

#endif