#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> rotateMatrix(vector<vector<int>> mat, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = i; j < N; ++j) {
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N/2; ++j) {
            int temp = mat[i][j];
            mat[i][j] = mat[i][N - j - 1];
            mat[i][N - j - 1] = temp;
        }
    }

    return mat;
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> mat(N, vector<int> (N, 0));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> mat[i][j];
        }
    }

    vector<vector<int>> result = rotateMatrix(mat, N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}