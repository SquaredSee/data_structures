#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// A templated doubly linked list with copy-swap implemented

#include <iostream> // std::std::cout, std::endl
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
    LinkedList():
        size(0),
        dummy(new Node<T>()) {

            dummy->next = dummy;
            dummy->prev = dummy;
    }

    ~LinkedList() {
        std::cout << "deconstructing " << this << std::endl;
        clear_list();
        delete dummy;
    }

    // copy constructor
    LinkedList(const LinkedList<T>& other):
        size(0),
        dummy(new Node<T>()) {

            std::cout << "copying " << &other << " into " << this << std::endl;
            dummy->next = dummy;
            dummy->prev = dummy;

            Node<T>* current = other.dummy->next;
            while (current != other.dummy) {
                add(size, current->data);
                current = current->next;
            }
    }

    // assignment operator
    LinkedList<T>& operator=(LinkedList<T> other) {
        std::cout << "assigning " << this << " to " << &other << std::endl;
        swap(*this, other);

        return *this;
    }

    friend void swap(LinkedList<T>& first, LinkedList<T>& second) {
        std::cout << "swapping " << &first << " and " << &second << std::endl;
        // enable ADL
        using std::swap;

        // by swapping the members of two objects,
        // the two objects are effectively swapped
        swap(first.size, second.size);
        swap(first.dummy, second.dummy);
    }

    void add(int i, T x) {
        assert(i >= 0 && i <= size);
        AddBefore(GetNode(i), x);
    }

    T get(int i) const {
        assert(i >= 0 && i < size);
        Node<T>* x = GetNode(i);
        T y = x->data;
        return y;
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

    void clear_list() {
        Node<T>* n = dummy->next;
        while (n != dummy) {
            Node<T>* temp = n;
            n = n->next;
            delete temp;
        }
        dummy->next = dummy;
        dummy->prev = dummy;
        size = 0;
    }

    void print() {
        Node<T>* n = dummy->next;
        while (n != dummy) {
            std::cout << n->data << std::endl;
            n = n->next;
        } 
    }

    int get_length() {
        return size;
    }



private:
    int size;
    Node<T>* dummy; // dummy works as both the head and tail

    Node<T>* GetNode(int i) {
        // assert(i >= 0 && i < size);

        Node<T>* n;
        if (i < size / 2) {
            n = dummy->next;
            for (int j = 0; j < i; ++j) {
                n = n->next;
            }

        }
        else {
            n = dummy;
            for (int j = size; j > i; --j) {
                n = n->prev;
            }
        }
        return n;
    }

    Node<T>* GetNode(int i) const {
        // assert(i >= 0 && i < size);

        Node<T>* n;
        if (i < size / 2) {
            n = dummy->next;
            for (int j = 0; j < i; ++j) {
                n = n->next;
            }

        }
        else {
            n = dummy;
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