#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    n = (((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1));

    cout << n << endl;

    return 0;
}