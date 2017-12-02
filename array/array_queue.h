#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

// ArrayQueue uses modular arithmetic to simulate an infinite array
// allowing for O(1) time (not counting resize() calls)

#include <algorithm> // std::max
#include <iostream> // std::cout, std::endl
#include "array.h"

template <typename T>
class ArrayQueue {
public:
    // starts with 10 items if i is not given, or if i is < 10
    ArrayQueue(int i = 0):
        j(0),
        n(0),
        arr(std::max(i, 10)) {}

    void enqueue(T x) {
        if (n + 1 > arr.length()) {
            resize();
        }
        // will wrap around to beginning if j+n > arr.length()
        arr[(j + n) % arr.length()] = x;
        ++n;
    }

    T dequeue() {
        T x = arr[j];
        arr[j] = T(); // assign now unused index j to default constructor T
        j = (j + 1) % arr.length(); // get new j with modular arithmetic
        --n;

        if (arr.length() > 3 * n) {
            resize();
        }

        return x;
    }

    void resize() {
        // creates new temp array and populates with data from arr
        // then sets arr equal to temp and sets j to 0
        Array<T> temp(std::max(2 * n, 1));
        for (int i = 0; i < n; ++i) {
            temp[i] = arr[(j + i) % arr.length()];
        }
        arr = temp;
        j = 0;
    }

    void print() {
        for (int i = j; i < n; ++i) {
            std::cout << arr[i] << std::endl;
        }
    }

private:
    int j; // beginning index of arr
    int n; // number of items in arr
    Array<T> arr;
};

#endif // ARRAY_QUEUE_H