#include <iostream>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    int matrix[r][c];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (matrix[i][j] == 0) {
                for (int k = 0; k < r; k++) {
                    if (matrix[i][k] != 0) {
                        matrix[i][k] = -1;
                    }
                }
                for (int k = 0; k < c; k++) {
                    if (matrix[k][j] != 0) {
                        matrix[k][j] = -1;
                    }
                }
            }
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (matrix[i][j] == -1) {
                matrix[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
