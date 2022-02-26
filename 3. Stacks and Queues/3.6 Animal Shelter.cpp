#include <iostream>
#include "imports/Stack.h"
using namespace std;

class AnimalShelter {
    Node<int>* dog;
    Node<int>* cat;

public:
    AnimalShelter() {
        dog = NULL;
        cat = NULL;
    }
    void enqueue(int age, bool isDog = true) {
        Node<int>* node;
        if (isDog) {       
            if (dog == NULL) {
                dog = new Node<int>(age);
                return;
            } else if (dog->data < age) {
                Node<int>* temp = new Node<int>(age);
                temp->next = dog;
                dog = temp;
                return;
            } else {
                node = dog;
            }
        } else {
            if (cat == NULL) {
                cat = new Node<int>(age);
                return;
            } else if (cat->data < age) {
                Node<int>* temp = new Node<int>(age);
                temp->next = cat;
                cat = temp;
                return;
            } else {
                node = cat;
            }
        }

        while (node->next != NULL && node->next->data > age) {
            node = node->next;
        }
        Node<int>* temp = new Node<int>(age);
        temp->next = node->next;
        node->next = temp;
    }
    Node<int>* dequeueAny() {
        Node<int>* res = NULL;
        if (dog != NULL && dog->data >= cat->data) {
            res = dog;
            dog = dog->next;
        } else if (cat != NULL) {
            res = cat;
            cat = cat->next;
        }

        return res;
    }
    Node<int>* dequeueDog() {
        Node<int>* res = dog;

        if (dog != NULL) {
            dog = dog->next;
        }

        return res;
    }
    Node<int>* dequeueCat() {
        Node<int>* res = cat;

        if (cat != NULL) {
            cat = cat->next;
        }

        return res;
    }
};

int main() {
    AnimalShelter as;

    as.enqueue(2, true);
    as.enqueue(8, true);
    as.enqueue(4, true);
    as.enqueue(3, false);
    as.enqueue(9, false);
    as.enqueue(5, false);

    cout << as.dequeueAny()->data << endl;
    cout << as.dequeueAny()->data << endl;
    cout << as.dequeueDog()->data << endl;
    cout << as.dequeueCat()->data << endl;

    return 0;
}