#include <iostream>
#include "imports/LinkedList.h"
using namespace std;

void removeDups(Node<int>* head) {
    while (head && head->next != NULL) {
        Node<int>* node = head;
        while (node->next != NULL) {
            if (node->next->data == head->data) {
                node->next = node->next->next;
                continue;
            }
            node = node->next;
        }
        head = head->next;
    }
}

int main() {
    Node<int>* head = new Node<int>(-1);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int data;
        cin >> data;
        head->insert(data);
    }
    head = head->next;

    removeDups(head);

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;

    return 0;
}