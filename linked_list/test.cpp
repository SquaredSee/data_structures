#include <iostream>
#include <string>
#include "linked_list.h"
#include "linked_list_stack.h"

using namespace std;

int main() {
    LinkedList<int> x;
    x.add(0, 7);
    x.add(1, 8);
    x.add(2, 9);
    x.add(3, 10);
    x.add(4, 11);
    x.add(5, 12);
    int xx = x.get(1);
    cout << xx << endl;
    cout << x.remove(3) << endl;
    x.print();

    // LinkedList<int> z;
    // z.add(0,1);
    // z.print();
    // z = x;
    // z.print();

    LLStack<int> y;
    y.push(1);
    y.push(2);
    y.push(3);
    y.push(4);
    y.push(5);
    y.print();
    cout << y.get(3) << endl;
    cout << y.pop() << endl;
    cout << y.pop() << endl;
    y.print();
}