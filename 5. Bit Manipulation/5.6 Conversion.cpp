#include <iostream>
using namespace std;

int conversion(int a, int b) {
    int cnt = 0;

    for (int i = a ^ b; i != 0; i = i & (i - 1)) {
        cnt++;
    }

    return cnt;
}

int main() {
    int a, b;
    cin >> a >> b;

    cout << conversion(a, b) << endl;

    return 0;
}