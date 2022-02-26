#include <iostream>
#include "imports/Stack.h"
using namespace std;

void sortedStack(Stack<int> &stk) {
    Stack<int> temp;

    int sorted = 0;
    while (sorted != stk.length()) {
        int maxE = stk.top();
        stk.pop();

        while (stk.length() > sorted) {
            if (stk.top() > maxE) {
                temp.push(maxE);
                maxE = stk.top();
            } else {
                temp.push(stk.top());
            }
            stk.pop();
        }

        stk.push(maxE);
        sorted++;

        while (!temp.isEmpty()) {
            stk.push(temp.top());
            temp.pop();
        }
    }
}

int main() {
    Stack<int> s;

    s.push(40);
    s.push(30);
    s.push(10);
    s.push(20);
    s.push(50);

    sortedStack(s);

    while (!s.isEmpty()) {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}