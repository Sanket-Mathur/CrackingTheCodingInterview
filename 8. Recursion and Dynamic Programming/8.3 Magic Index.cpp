#include <iostream>
#include <vector>
using namespace std;

int magicIndex(vector<int> &arr, int low, int high) {
    if (low > high) {
        return -1;
    }

    int mid = low + (high - low) / 2;
    if (arr[mid] == mid) {
        return mid;
    }

    int leftIndex = min(mid - 1, arr[mid]), rightIndex = max(mid + 1, arr[mid]);

    int leftRes = magicIndex(arr, low, leftIndex);
    if (leftRes >= 0) {
        return leftIndex;
    }
    return magicIndex(arr, rightIndex, high);
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = magicIndex(arr, 0, n - 1);
    if (result >= 0) {
        cout << result << endl;
    } else {
        cout << "No such index." << endl;
    }

    return 0;
}