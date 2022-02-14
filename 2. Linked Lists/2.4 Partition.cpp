#include <iostream>
#include "imports/LinkedList.h"
using namespace std;

Node<int>* partition(Node<int>* head, int k) {
    Node<int>* node = head;
    while (node->next != NULL) {
        if (node->next->data < k) {
            Node<int>* temp = node->next;
            node->next = node->next->next;
            temp->next = head;
            head = temp;
        } else {
            node = node->next;
        }
    }

    return head;
}

int main() {
    Node<int>* head = new Node<int>(-1);
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        head->insert(num);
    }
    head = head->next;
    cin >> k;

    head = partition(head, k);
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }

    return 0;
}