#include<iostream>
#include<stack>
#include "imports/LinkedList.h"
using namespace std;

bool palindrome(Node<int>* head) {
    int size = 0;
    Node<int>* node = head;
    while (node != NULL) {
        ++size;
        node = node->next;
    }

    stack<Node<int>*> s;
    for (int i = 0; i < size / 2; ++i) {
        s.push(head);
        head = head->next;
    }

    if (size % 2 == 1) {
        head = head->next;
    }

    while (!s.empty()) {
        if (s.top()->data != head->data) {
            return false;
        }
        s.pop();
        head = head->next;
    }

    return true;
}

int main() {
    Node<int>* head = new Node<int>(-1);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int input;
        cin >> input;
        head->insert(input);
    }
    head = head->next;

    if (palindrome(head)) {
        cout << "Palindrome" << endl;
    } else {
        cout << "Not Palindrome" << endl;
    }

    return 0;
}