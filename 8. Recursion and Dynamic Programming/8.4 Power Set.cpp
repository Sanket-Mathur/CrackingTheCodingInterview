#include <iostream>
#include <vector>
using namespace std;

void powerSet(vector<int> &arr, vector<int> set, vector<vector<int>> &result, int i = -1) {
    if (i >= 0) {
        set.push_back(arr[i]);
    }
    result.push_back(set);

    for (int j = i + 1; j < arr.size(); ++j) {
        powerSet(arr, set, result, j);
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int> set;
    vector<vector<int>> result;
    powerSet(arr, set, result);

    for (auto s : result) {
        for (auto i : s) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}