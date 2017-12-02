#include <iostream>
#include <string>
#include "array.h"
#include "array_stack.h"
#include "array_queue.h"

using namespace std;

int main() {
    ArrayStack<string> x;
    x.push("test");
    x.push("test2");
    x.print();
    cout << x.pop() << endl;
    cout << x.pop() << endl;
    x.print();

    ArrayQueue<int> y;
    y.enqueue(6);
    y.enqueue(5);
    y.print();
    cout << y.dequeue() << endl;
    y.print();
    cout << y.dequeue() << endl;
    y.print();
}