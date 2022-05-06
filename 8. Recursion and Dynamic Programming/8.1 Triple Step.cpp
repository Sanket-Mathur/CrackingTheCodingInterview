#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int steps[n + 1];
    steps[0] = 1;
    steps[1] = 1;
    steps[2] = 2;
    for (int i = 3; i < n + 1; ++i) {
        steps[i] = steps[i - 1] + steps[i - 2] + steps[i - 3];
    }

    cout << steps[n] << endl;

    return 0;
}