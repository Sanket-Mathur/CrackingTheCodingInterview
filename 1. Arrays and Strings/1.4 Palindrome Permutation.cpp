#include <iostream>
using namespace std;

bool checkPalinPermutation(string s) {
    int count[256] = {0};
    for (int i = 0; i < s.length(); ++i) {
        count[(int)s[i]] += 1;
    }

    bool odd = false;
    for (int i = 0; i < 256; ++i) {
        if (count[i] % 2 != 0) {
            if (odd) {
                return false;
            } else {
                odd = true;
            }
        }
    }

    return true;
}

int main() {
    string s;
    getline(cin, s);

    if (checkPalinPermutation(s)) {
        cout << "Palindromic Permutation is available." << endl;
    } else {
        cout << "No palindromic Permutation is available." << endl;
    }

    return 0;    
}