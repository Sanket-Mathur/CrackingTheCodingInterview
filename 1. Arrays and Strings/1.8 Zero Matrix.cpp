#include <iostream>
#include <vector>
using namespace std;

void zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
    bool hasZeroR = false, hasZeroC = false;
    for (int i = 0; i < n; ++i) {
        if (matrix[i][0] == 0) {
            hasZeroC = true;
            break;
        }
    }
    for (int j = 0; j < m; ++j) {
        if (matrix[0][j] == 0) {
            hasZeroR = true;
            break;
        }
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (matrix[i][0] == 0) {
            for (int j = 0; j < m; ++j) {
                matrix[i][j] = 0;
            }
        }
    }
    for (int j = 0; j < m; ++j) {
        if (matrix[0][j] == 0) {
            for (int i = 1; i < n; ++i) {
                matrix[i][j] = 0;
            }
        }
    }

    if (hasZeroC) {
        for (int i = 0; i < n; ++i) {
            matrix[i][0] = 0;
        }
    }
    if (hasZeroC) {
        for (int j = 0; j < m; ++j) {
            matrix[0][j] = 0;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int> (m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    zeroMatrix(matrix, n, m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}