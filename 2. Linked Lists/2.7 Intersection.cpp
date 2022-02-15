#include <iostream>
#include "imports/LinkedList.h"
using namespace std;

bool intersection(Node<int>* head1, Node<int>* head2) {
    while (head1->next != NULL) {
        head1 = head1->next;
    }
    while (head2->next != NULL) {
        head2 = head2->next;
    }

    if (head1 == head2) {
        return true;
    }
    return false;
}

int main() {
    Node<int>* head1 = new Node<int>(-1);
    Node<int>* head2 = new Node<int>(-1);

    head1->insert(1);
    head1->insert(2);
    head1->insert(3);
    head1->insert(4);

    head2->insert(1);
    head2->insert(2);
    head2->insert(3);
    head2->insert(4);

    Node<int>* node1 = head1;
    node1 = node1->next->next;

    Node<int>* node2 = head2;
    while (node2->next != NULL) {
        node2 = node2->next;
    }
    node2->next = node1;

    if (intersection(head1, head2)) {
        cout << "Intersection" << endl;
    } else {
        cout << "No intersection" << endl;
    }

    return 0;
}