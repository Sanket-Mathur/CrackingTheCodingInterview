#include <iostream>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    int n = s.length();

    int space = n - 1, text;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] != ' ') {
            text = i;
            break;
        }
    }

    cout << text << " " << space << endl;

    while (text > 0 && text < space && space > 2) {
        if (s[text] != ' ') {
            s[space--] = s[text];
        } else {
            s[space--] = '0';
            s[space--] = '2';
            s[space--] = '%';
        }
        text--;
    }

    cout << s << endl;

    return 0;
}