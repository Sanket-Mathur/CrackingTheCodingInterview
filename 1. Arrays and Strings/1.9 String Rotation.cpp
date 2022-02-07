#include <iostream>
using namespace std;

bool subString(string s1, string s2) {
    if (s2.length() > s1.length()) {
        return false;
    }

    for (int i = 0; i < s1.length() - s2.length() + 1; i++) {
        bool subFound = true;
        for (int j = i, k = 0; j < i + s2.length(); ++j, ++k) {
            if (s1[j] != s2[k]) {
                subFound = false;
                break;
            }
        }
        if (subFound) {
            return true;
        }
    }

    return false;
}

bool stringRotation(string s1, string s2) {
    if (s1.length() != s2.length()) {
        return false;
    }

    return subString(s1 + s1, s2);
}

int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    if (stringRotation(s1, s2)) {
        cout << "String Rotation" << endl;
    } else {
        cout << "Not a String Rotation" << endl;
    }

    return 0;
}