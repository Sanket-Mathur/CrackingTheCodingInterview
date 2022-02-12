#include <iostream>
#include "imports/LinkedList.h"
using namespace std;

Node<int>* DeleteMiddle(Node<int>* head) {
    if (head == NULL) {
        return NULL;
    }

    Node<int>* fast;
    Node<int>* slow =  head;
    if (head->next != NULL && head->next->next != NULL) {
        fast = head->next->next;
    } else {
        return head->next;
    }

    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = slow->next->next;

    return head;
}

int main() {
    Node<int>* head = new Node<int>(-1);
    int n, k;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        head->insert(temp);
    }
    head = head->next;

    Node<int>* result = DeleteMiddle(head);
    while (result != NULL) {
        cout << result->data << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}