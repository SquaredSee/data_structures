#include <iostream>
#include <string>
#include "array.h"
#include "array_stack.h"
#include "array_queue.h"

using namespace std;

// template <typename T>
// class test {
// public:
//     test(int s) {
//         a = new Array<T>(20);
//     }
//     Array<T> a;
// };

int main() {
    // Array<int> test(20);
    // for (int i = 0; i < test.length(); ++i) {
    //     test[i] = i;
    // }
    // for (int i = 0; i < test.length(); ++i) {
    //     cout << test[i] << endl;
    // }

    ArrayQueue<int> y;
    y.enqueue(6);
    y.enqueue(5);
    y.print();
    cout << y.dequeue() << endl;
    cout << y.dequeue() << endl;
    y.print();
}