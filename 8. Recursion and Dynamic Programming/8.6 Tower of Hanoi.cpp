#include <iostream>
#include <vector>
using namespace std;

void printTower(vector<vector<int>> &pegs) {
    for (int i = 0; i < pegs.size(); ++i) {
        cout << "[" << i << "] -> ";
        for (auto j : pegs[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void towerOfHanoi(vector<vector<int>> &pegs, int n, int source, int dest, int aux) {
    if (n == 1) {
        pegs[dest].push_back(pegs[source][pegs[source].size() - 1]);
        pegs[source].pop_back();
        printTower(pegs);
    } else {
        towerOfHanoi(pegs, n - 1, source, aux, dest);

        pegs[dest].push_back(pegs[source][pegs[source].size() - 1]);
        pegs[source].pop_back();
        printTower(pegs);

        towerOfHanoi(pegs, n - 1, aux, dest, source);
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> pegs(3);
    for (int i = n; i > 0; --i) {
        pegs[0].push_back(i);
    }
    printTower(pegs);

    towerOfHanoi(pegs, n, 0, 2, 1);

    return 0;
}