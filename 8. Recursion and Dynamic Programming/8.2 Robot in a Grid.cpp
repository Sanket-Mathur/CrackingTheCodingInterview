#include <iostream>
#include <vector>
using namespace std;

bool findPath(vector<vector<int>> &grid, vector<char> &path, int i = 0, int j = 0) {
    int n = grid.size(), m = grid[0].size();
    if (i == n - 1 && j == m - 1) {
        return true;
    } else if (i == n || j == m || grid[i][j] == 0) {
        return false;
    }

    path.push_back('D');
    if (findPath(grid, path, i + 1, j)) {
        return true;
    }
    path.pop_back();

    path.push_back('R');
    if (findPath(grid, path, i, j + 1)) {
        return true;
    }
    path.pop_back();

    grid[i][j] = 0;
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int> (m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    vector<char> path;
    if (findPath(grid, path)) {
        for (auto i : path) {
            cout << i << " ";
        }
        cout << endl;
    } else {
        cout << "No path found." << endl;
    }

    return 0;
}