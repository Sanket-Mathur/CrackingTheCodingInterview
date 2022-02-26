#include <iostream>
using namespace std;

#ifndef ARRAYLIST_INCLUDE
#define ARRAYLIST_INCLUDE

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(T data) {
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class Stack {
    Node<T>* head;
    int size;

public:
    Stack() {
        head = NULL;
        size = 0;
    }
    void push(T item) {
        Node<T>* newNode = new Node<T>(item);
        newNode->next = head;
        head = newNode;

        size++;
    }
    void pop() {
        if (isEmpty()) {
            cout << "Underflow" << endl;
            return;
        }
        head = head->next;
        size--;
    }
    T top() {
        if (isEmpty()) {
            cout << "Underflow" << endl;
            return T();
        }
        return head->data;
    }
    bool isEmpty() {
        return head == NULL;
    }
    int length() {
        return size;
    }
};

#endif