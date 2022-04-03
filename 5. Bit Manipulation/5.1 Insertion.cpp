#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int binaryToDecimal(string str) {
    int result = 0;
    for (int i = str.length() - 1, j = 0; i >= 0; --i, ++j) {
        result += str[i] == '1' ? pow(2, j) : 0;
    }

    return result;
}

string decimalToBinary(int n) {
    string result;
    while (n > 0) {
        if (n % 2 == 0) {
            result += '0';
        } else {
            result += '1';
        }

        n /= 2;
    }

    return string(result.rbegin(), result.rend());
}

int main() {
    string nstr, mstr;
    int i, j;

    getline(cin, nstr);
    getline(cin, mstr);
    cin >> i >> j;

    int n, m;
    n = binaryToDecimal(nstr);
    m = binaryToDecimal(mstr);

    int mask = ((~0) << (j + 1)) | ((1 << i) - 1);
    int result = (n & mask) | (m << i);

    cout << decimalToBinary(result) << endl;

    return 0;
}