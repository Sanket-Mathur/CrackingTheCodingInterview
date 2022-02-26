#include <iostream>
#include "imports/Stack.h"
using namespace std;

class PlateStack {
    Stack<Stack<int>*>* plates;
    int size;
public:
    PlateStack(int s) {
        plates = new Stack<Stack<int>*>;
        size = s;
    }
    
    void push(int item) {
        if (plates->isEmpty() || plates->top()->length() == size) {
            Stack<int>* newStack = new Stack<int>();
            plates->push(newStack);
        }
        plates->top()->push(item);
    }
    void pop() {
        if (plates->isEmpty()) {
            cout << "Underflow" << endl;
            return;
        }

        plates->top()->pop();

        if (plates->top()->length() == 0) {
            plates->pop();
        }
    }
    int top() {
        if (plates->isEmpty()) {
            cout << "Underflown" << endl;
            return -1;
        }

        return plates->top()->top();
    }
};

int main() {
    PlateStack s(5);

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.push(9);
    s.push(10);
    s.push(11);
    s.push(12);
    s.push(13);
    s.push(14);

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();

    return 0;
}