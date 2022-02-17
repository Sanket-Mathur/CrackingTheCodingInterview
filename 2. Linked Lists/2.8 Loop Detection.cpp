#include <iostream>
#include "imports/LinkedList.h"
using namespace std;

Node<char>* loopDetection(Node<char>* head) {
    Node<char>* fast = head;
    Node<char>* slow = head;

    while (fast->next != NULL && fast->next->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        
        if (fast == slow) {
            break;
        }
    }

    if (fast != slow) {
        return NULL;
    }

    fast = head;
    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }

    return slow;
}

int main() {
    Node<char>* n0 = new Node<char>('A');
    Node<char>* n1 = new Node<char>('B');
    Node<char>* n2 = new Node<char>('C');
    Node<char>* n3 = new Node<char>('D');
    Node<char>* n4 = new Node<char>('E');

    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2;

    Node<char>* result = loopDetection(n0);
    if (result == NULL) {
        cout << "No loop detected" << endl;
    } else {
        cout << "Loop detected and starts at " << result->data << endl;
    }

    return 0;
}