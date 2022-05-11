#include <iostream>
#include <vector>
using namespace std;

void permutations(string str, vector<string> &result, vector<bool> visited, string curr = "") {
    if (curr.length() == str.length()) {
        result.push_back(curr);
        return;
    }

    for (int i = 0; i < str.length(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            permutations(str, result, visited, curr + str[i]);
            visited[i] = false;
        }
    }
}

int main() {
    string str;
    cin >> str;

    vector<string> result;
    vector<bool> visited(str.length(), false);

    permutations(str, result, visited);

    for (auto i : result) {
        cout << i << endl;
    }

    return 0;
}