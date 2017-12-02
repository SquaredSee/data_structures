#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// A templated doubly linked list
// NOT USING COPY SWAP YET

#include <iostream> // std::cout, std::endl
#include <cassert> // assert

template <typename T>
struct Node {
    Node<T>* next;
    Node<T>* prev;
    T data;
};

template <typename T>
class LinkedList {
public:
    LinkedList() {
        size = 0;
        dummy.next = &dummy;
        dummy.prev = &dummy;
    }

    ~LinkedList() {
        Node<T>* n = dummy.next;
        while (n != &dummy) {
            Node<T>* temp = n;
            n = n->next;
            delete temp;
        }
        delete dummy;
        size = 0;
    }

    void add(int i, T x) {
        assert(i >= 0 && i <= size);
        AddBefore(GetNode(i), x);
    }

    T get(int i) {
        assert(i >= 0 && i < size);
        return GetNode(i)->data;
    }

    T set(int i, T x) {
        assert(i >= 0 && i < size);
        Node<T>* n = GetNode(i);
        T y = n->data;
        n->data = x;
        return y;
    }

    T remove(int i) {
        assert(i >= 0 && i < size);
        Node<T>* n = GetNode(i);
        T x = n->data;
        RemoveNode(n);
        return x;
    }

    void print() {
        Node<T>* n = dummy.next;
        while (n != &dummy) {
            std::cout << n->data << std::endl;
            n = n->next;
        } 
    }

    int length() {
        return size;
    }

private:
    int size;
    Node<T> dummy; // dummy works as both the head and tail

    Node<T>* GetNode(int i) {
        // assert(i >= 0 && i < size);

        Node<T>* n;
        if (i < size / 2) {
            n = dummy.next;
            for (int j = 0; j < i; ++j) {
                n = n->next;
            }

        }
        else {
            n = &dummy;
            for (int j = size; j > i; --j) {
                n = n->prev;
            }
        }
        return n;
    }

    void AddBefore(Node<T>* w, T x) {
        Node<T>* n = new Node<T>;
        n->data = x;
        n->prev = w->prev;
        n->next = w;
        n->next->prev = n;
        n->prev->next = n;
        ++size;
    }

    void RemoveNode(Node<T>* n) {
        n->prev->next = n->next;
        n->next->prev = n->prev;
        delete n;
        --size;
    }
};

#endif // LINKED_LIST_H