/* 
Example Array class implemented with the copy-swap idiom

Resources:
https://stackoverflow.com/questions/4172722/what-is-the-rule-of-three
https://stackoverflow.com/questions/3279543/what-is-the-copy-and-swap-idiom
https://stackoverflow.com/questions/5695548/public-friend-swap-member-function
https://stackoverflow.com/questions/4421706/what-are-the-basic-rules-and-idioms-for-operator-overloading/4421715
http://opendatastructures.org/ods-cpp.pdf chapter 2
*/

#ifndef ARRAY_H
#define ARRAY_H

#include <algorithm> // std::copy, std::swap
#include <cassert> // assert

template <typename T>
class Array {
public:
    // (default) constructor
    Array(int size = 0):
        size(size),
        arr(size ? new T[size]() : nullptr) {}

    // copy constructor
    Array(const Array<T>& other):
        size(other.size),
        arr(size ? new T[size]() : nullptr) {

        if (arr) {
            // std::copy(other.arr, other.arr + size, arr);

            for (int i = 0; i < size; ++i) {
                arr[i] = other[i];
            }
        }
    }

    // move constructor
    Array(Array<T>&& other):
        Array() { // initialize via default constructor, C++11 only
        
        swap(*this, other);
    }

    // destructor
    ~Array() {
        delete [] arr;
    }

    // assignment operator
    Array<T>& operator=(Array<T> other) {
        swap(*this, other);

        return *this;
    }

    // subscript operator
    T& operator[](int i) {
        assert(i >= 0 && i < size);
        return arr[i];
    }

    // subscript operator for const
    const T& operator[](int i) const {
        assert(i >= 0 && i < size);
        return arr[i];
    }
    
    friend void swap(Array<T>& first, Array<T>& second) {
        // enable ADL
        using std::swap;

        // by swapping the members of two objects,
        // the two objects are effectively swapped
        swap(first.size, second.size);
        swap(first.arr, second.arr);
    }

    int length() {
        return size;
    }


private:
    int size;
    T* arr;
};

#endif // ARRAY_H
