#include <iostream>
using namespace std;

#ifndef ARRAYLIST_INCLUDE
#define ARRAYLIST_INCLUDE

template <typename T>
class Stack {
    T* stack;
    int maxSize;
    int size;

public:
    Stack(int maxSize = 10) {
        this->maxSize = maxSize;
        stack = new T[maxSize];
        size = 0;
    }
    void push(T item) {
        if (size == maxSize) {
            cout << "Overflow" << endl;
            return;
        }
        stack[size++] = item;
    }
    void pop() {
        if (isEmpty()) {
            cout << "Underflow" << endl;
            return;
        }
        size--;
    }
    T top() {
        if (isEmpty()) {
            cout << "Underflow" << endl;
            return T();
        }
        return stack[size - 1];
    }
    bool isEmpty() {
        return size == 0;
    }
    int length() {
        return size;
    }
};

#endif