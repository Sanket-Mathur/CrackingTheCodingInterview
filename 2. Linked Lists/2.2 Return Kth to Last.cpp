#include <iostream>
#include "imports/LinkedList.h"
using namespace std;

Node<int>* KthToLast(Node<int>* head, int k) {
    if (head == NULL) {
        return NULL;
    }

    Node<int>* forw = head;
    Node<int>* back = head;
    
    for (int i = 0; i < k; ++i) {
        forw = forw->next;
        if (forw == NULL) {
            return NULL;
        }
    }
    
    while (forw != NULL) {
        back = back->next;
        forw = forw->next;
    }

    return back;
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

    cin >> k;

    Node<int>* result = KthToLast(head, k);
    if (!result) {
        cout << "Overflow" << endl;
    } else {
        cout << result->data << endl;
    }
    
    return 0;
}