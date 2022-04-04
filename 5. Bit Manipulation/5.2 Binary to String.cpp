#include <iostream>
using namespace std;

string binaryToString(float n) {
    string res = "0.";
    for (int i = 0; i < 32 && n > 0; i++) {
        n *= 2;
        if (n >= 1) {
            res += '1';
            n -= 1;
        } else {
            res += '0';
        }
    }

    if (n > 0) {
        return "ERROR";
    }
    return res;
}

int main() {
    float n;
    cin >> n;

    cout << binaryToString(n) << endl;

    return 0;
}