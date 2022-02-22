#include <iostream>
using namespace std;

int head1, head2, head3;

void push(int stkno, int a[], int n, int item) {
    if (stkno == 1) {
        if (head1 == n / 3) {
            cout << "Overflow" << endl;
            return;
        } else {
            a[head1++] = item;
        }
    } else if (stkno == 2)  {
        if (head2 == 2 * n / 3) {
            cout << "Overflow" << endl;
            return;
        } else {
            a[head2++] = item;
        }
    } else {
        if (head3 == n) {
            cout << "Overflow" << endl;
            return;
        } else {
            a[head3++] = item;
        }
    }
}

int pop(int stkno, int a[], int n) {
    if (stkno == 1) {
        if (head1 == 0) {
            cout << "Underflow" << endl;
            return -1;
        } else {
            int res = a[--head1];
            return res;
        }
    } else if (stkno == 2) {
        if (head2 == n / 3) {
            cout << "Underflow" << endl;
            return -1;
        } else {
            int res = a[--head2];
            return res;
        }
    } else {
        if (head3 == 2 * n / 3) {
            cout << "Underflow" << endl;
            return -1;
        } else {
            int res = a[--head3];
            return res;
        }
    }
}

int main() {
    int n;
    cin >> n;
    int a[n];

    head1 = 0;
    head2 = n / 3;
    head3 = 2 * n / 3;

    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        int stkno, oper;
        cin >> oper >> stkno;

        if (oper == 1) {
            int item;
            cin >> item;

            push(stkno, a, n, item);
        } else {
            int temp = pop(stkno, a, n);
            cout << temp << endl;
        }
    }    

    return 0;
}