#include <iostream>
using namespace std;

string stringCompression(string str) {
    string result = "";
    char curr = str[0];
    int count = 1;

    for (int i = 1; i < str.length(); ++i) {
        if (str[i] == curr) {
            ++count;
        } else {
            result = result + curr + to_string(count);
            curr = str[i];
            count = 1;
        }
    }
    result = result + curr + to_string(count);

    return result;
}

int main() {
    string str;
    getline(cin, str);

    cout << stringCompression(str) << endl;

    return 0;
}