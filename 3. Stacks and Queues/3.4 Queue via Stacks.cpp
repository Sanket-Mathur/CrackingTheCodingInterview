#include <iostream>
#include "imports/Stack.h"
using namespace std;

class Queue {
    Stack<int>* stk;
    Stack<int>* temp;

public:
    Queue() {
        stk = new Stack<int>;
        temp = new Stack<int>;
    }
    void enqueue(int item) {
        stk->push(item);
    }
    int dequeue() {
        while (!stk->isEmpty()) {
            temp->push(stk->top());
            stk->pop();
        }

        int res = temp->top();
        temp->pop();

        while (!temp->isEmpty()) {
            stk->push(temp->top());
            temp->pop();
        }

        return res;
    }
};

int main() {
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    return 0;
}