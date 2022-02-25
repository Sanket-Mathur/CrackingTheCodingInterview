#include <iostream>
#include "imports/Stack.h"
using namespace std;

class MinStack {
    Stack<int>* stk;
    Stack<int>* mins;
public:
    MinStack() {
        stk = new Stack<int>;
        mins = new Stack<int>;
    }

    void push(int item) {
        if (mins->isEmpty() || item <= mins->top()) {
            mins->push(item);
        }
        stk->push(item);
    }
    void pop() {
        if (stk->isEmpty()) {
            cout << "Underflow" << endl;
            return;
        }

        if (stk->top() == mins->top()) {
            mins->pop();
        }
        stk->pop();
    }
    int min() {
        if (mins->isEmpty()) {
            cout << "Underflow" << endl;
            return -1;
        }
        return mins->top();
    }
};

int main() {
    MinStack s;

    s.push(10);
    s.push(8);
    s.push(13);
    s.push(7);
    s.push(5);

    cout << s.min() << endl;
    s.pop();
    cout << s.min() << endl;
    s.pop();
    cout << s.min() << endl;
    s.pop();
    cout << s.min() << endl;
    s.pop();
    cout << s.min() << endl;
    s.pop();

    return 0;
}