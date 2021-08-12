// This is the templated version of the IntArray we made before.
// We will now be able to handle all the fundamental data types
// in just one class.

// This is named ".hpp". Sort of a personal convention because
// template functions definitions are usually placed into their 
// .h header file.

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cassert> // For Assert()

template <class T>
class Array
{
private:
    int m_length{};
    T* m_data{};
public:
    Array(int length)
    {
        assert(length > 0);
        m_data = new T[length]{};
        m_length = length;
    }

    Array(const Array&) = delete;
    Array& operator=(const Array&) = delete;

    ~Array()
    {
        delete[] m_data;
    }

    void erase()
    {
        delete[] m_data;
        m_data = nullptr;
        m_length = 0;
    }

    T& operator[](int index)
    {
        assert(index >= 0 && index < m_length && "Index out of bounds");
        return m_data[index];
    }

    // templated getLength() function defined below
    int getLength() const;
};

// Function definitions //

template<typename T>
int Array<T>::getLength() const {
    return m_length;
}

#endif