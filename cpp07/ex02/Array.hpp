#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array
{
private:
    T *array;
    unsigned int arrSize;

public:
    Array() : array(NULL), arrSize(0) {}

    Array(unsigned int n) : arrSize(n)
    {
        array = new T[n]();
    }

    Array(Array const &other) : arrSize(other.arrSize)
    {
        array = new T[arrSize];
        for (unsigned int i = 0; i < arrSize; i++)
        {
            array[i] = other.array[i];
        }
    }

    Array &operator=(Array const &other)
    {
        if (this != &other)
        {
            delete[] array;
            arrSize = other.arrSize;
            array = new T[arrSize];
            for (unsigned int i = 0; i < arrSize; i++)
            {
                array[i] = other.array[i];
            }
        }
        return *this;
    }

    ~Array()
    {
        delete[] array;
    }

    T &operator[](unsigned int index)
    {
        if (index >= arrSize)
        {
            throw std::exception();
        }
        return array[index];
    }

    T const &operator[](unsigned int index) const
    {
        if (index >= arrSize)
        {
            throw std::exception();
        }
        return array[index];
    }

    unsigned int size() const
    {
        return arrSize;
    }
};

#endif
