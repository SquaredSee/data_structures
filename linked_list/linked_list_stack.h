#ifndef LINKED_LIST_STACK_H
#define LINKED_LIST_STACK_H

#include "linked_list.h"
#include <iostream> // std::cout, std::endl

template <typename T>
class LLStack {
public:
    void push(T x) {
        list.add(0, x);
    }

    T pop() {
        T x = list.remove(0);
        return x;
    }

    T get(int i) {
        return list.get(i);
    }

    void print() {
        list.print(); 
    }

    int get_length() {
        return list.get_length();
    }

private:
    LinkedList<T> list; // dummy works as both the head and tail
};

#endif // LINKED_LIST_STACK_H