#ifndef ARRAYLIST_INCLUDE
#define ARRAYLIST_INCLUDE

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node(T data) {
        this->data = data;
        next = NULL;
    }
    void insert(T data) {
        if (next == NULL) {
            next = new Node<T>(data);
        } else {
            next->insert(data);
        }
    }
};

#endif