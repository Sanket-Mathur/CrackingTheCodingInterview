#include <iostream>
using namespace std;

int recursiveMultiply(int a, int b) {
    if (b == 0) {
        return 0;
    }

    int res = 0;
    if (b & 1) {
        res = a;
    }

    res += recursiveMultiply(a, b >> 1) << 1;

    return res;
}

int main() {
    int a, b;
    cin >> a >> b;

    cout << recursiveMultiply(a, b) << endl;

    return 0;
}