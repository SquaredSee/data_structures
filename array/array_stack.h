#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#include <algorithm> // std::max
#include <iostream> // std::cout, std::endl
#include "array.h"

template <typename T>
class ArrayStack {
public:
    // starts with 10 items if i is not given, or if i is < 10
    ArrayStack(int i = 0):
        n(0),
        arr(std::max(i, 10)) {}

    void push(T x) {
        if (n + 1 > arr.length()) {
            resize();
        }
        arr[n] = x;
        ++n;
    }

    T pop() {
        T x = arr[n - 1];
        arr[n - 1] = T();
        --n;

        if (arr.length() > 3 * n) {
            resize();
        }

        return x;
    }

    void resize() {
        Array<T> temp(std::max(2 * n, 1));
        for (int i = 0; i < arr.length(); ++i) {
            temp[i] = arr[i];
        }
        arr = temp;
    }

    void print() {
        for (int i = 0; i < n; ++i) {
            std::cout << arr[i] << std::endl;
        }
    }

private:
    int n; // number of items in arr
    Array<T> arr;
};

#endif // ARRAY_STACK_H