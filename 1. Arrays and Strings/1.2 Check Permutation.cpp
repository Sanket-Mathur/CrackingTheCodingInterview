#include <iostream>
using namespace std;

bool checkPermutation(string str1, string str2) {
    if (str1.length() != str2.length()) {
        return false;
    }

    int counts[256] = {0};
    for (int i = 0; i < str1.length(); ++i) {
        counts[(int)str1[i]] += 1;
    }

    for (int i = 0; i < str2.length(); ++i) {
        if (counts[(int)str2[i]] <= 0) {
            return false;
        }
        counts[(int)str2[i]] -= 1;
    }
    return true;
}

int main() {
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);

    if (checkPermutation(str1, str2)) {
        cout << "Both strings are permutations of each other." << endl;
    } else {
        cout << "Strings are not permutations of each other." << endl;
    }

    return 0;
}