#include <iostream>
#include "imports/LinkedList.h"
using namespace std;

Node<int>* addRTL(Node<int>* head1, Node<int>* head2) {
    Node<int>* resultHead = new Node<int>(-1);
    Node<int>* node = resultHead;
    int rem = 0;

    while (head1 != NULL && head2 != NULL) {
        node->next = new Node<int>((head1->data + head2->data + rem) % 10);
        rem = (head1->data + head2->data + rem) / 10;
        node = node->next;
        head1 = head1->next;
        head2 = head2->next;
    }

    while (head1 != NULL) {
        node->next = new Node<int>((head1->data  + rem) % 10);
        rem = (head1->data + rem) / 10;
        node = node->next;
        head1 = head1->next;
    }
    while (head2 != NULL) {
        node->next = new Node<int>((head2->data + rem) % 10);
        rem = (head2->data + rem) / 10;
        node = node->next;
        head2 = head2->next;
    }

    while (rem > 0) {
        node->next = new Node<int>(rem % 10);
        rem /= 10;
        node = node->next;
    }

    return resultHead->next;
}

int main() {
    Node<int>* head1 = new Node<int>(-1);
    Node<int>* head2 = new Node<int>(-1);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        head1->insert(temp);
    }
    head1 = head1->next;
    for (int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        head2->insert(temp);
    }
    head2 = head2->next;

    Node<int>* result = addRTL(head1, head2);
    while (result != NULL) {
        cout << result->data << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}