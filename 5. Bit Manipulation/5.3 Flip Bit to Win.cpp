#include <iostream>
using namespace std;

int findMaxLen(int n) {
    if (~n == 0) {
        return INT32_MAX;
    }

    int currLen = 0, prevLen = 0;
    int maxLen = 1;
    while (n > 0) {
        if ((n & 1) == 1) {
            ++currLen;
        } else {
            prevLen = (n & 2) == 0 ? 0 : currLen;
            currLen = 0;
        }

        maxLen = max(maxLen, currLen + prevLen + 1);
        n >>= 1;
    }

    return maxLen;
}

int main() {
    int num;
    cin >> num;

    cout << findMaxLen(num) << endl;

    return 0;
}