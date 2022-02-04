#include <iostream>
using namespace std;

bool isUnique(string s) {
    if (s.length() > 256) {
        return false;
    }

    bool record[256] = {0};
    for (int i = 0; i < s.length(); ++i) {
        if (record[(int)s[i]]) {
            return false;
        }
        record[(int)s[i]] = true;
    }

    return true;
}

int main() {
    string s;
    getline(cin, s);

    if (isUnique(s)) {
        cout << "All characters are unique." << endl;
    } else {
        cout << "All characters are not unique." << endl;
    }

    return 0;
}