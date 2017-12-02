#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

#include <algorithm> // std::max
#include <iostream>
#include "array.h"

template <typename T>
class ArrayQueue {
public:
    // starts with 10 items if i is not given, or if i is < 10
    ArrayQueue(int i = 0):
        n(0),
        arr(std::max(i, 10)) {}

    void enqueue(T x) {
        if (n + 1 > arr.length()) {
            resize();
        }
        arr[n] = x;
        ++n;
    }

    T dequeue() {
        T x = arr[0];
        //arr[0] = T();

        if (x) {
            //std::copy(arr[1], arr[n], arr[0]);
            for (int i = 1; i < n; ++i) {
                arr[i - 1] = arr[i];
            }
            // replace the now unused arr[n-1] with default type constructor
            arr[n - 1] = T();
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

#endif // ARRAY_QUEUE_H