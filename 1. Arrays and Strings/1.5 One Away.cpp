#include <iostream>
using namespace std;

bool oneAway(string a, string b) {
    if (abs((int)(a.length() - b.length())) > 1) {
        return false;
    }

    int x = 0;
    while (x < a.length() && x < b.length() && a[x] == b[x]) {
        ++x;
    }

    int i = a.length() - 1, j = b.length() - 1;
    while (i > x && j > x && a[i] == b[j]) {
        --i;
        --j;
    }

    return (i == x || j == x);
}

int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);

    if (oneAway(a, b)) {
        cout << "Strings are one away" << endl;
    } else {
        cout << "Strings are not one away" << endl;
    }

    return 0;
}