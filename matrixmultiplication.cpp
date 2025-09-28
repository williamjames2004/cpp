#include <iostream>
using namespace std;

// Recursive function to multiply matrices
void multiplyRecursive(int A[][10], int B[][10], int C[][10],
                       int row1, int col1, int col2,
                       int i = 0, int j = 0, int k = 0) {
    // Base condition: if i >= row1, we are done
    if (i >= row1) return;

    // If j < col2, we are still filling row i of C
    if (j < col2) {
        // If k < col1, keep adding A[i][k] * B[k][j]
        if (k < col1) {
            C[i][j] += A[i][k] * B[k][j];
            multiplyRecursive(A, B, C, row1, col1, col2, i, j, k + 1);
        } else {
            // Move to next column
            multiplyRecursive(A, B, C, row1, col1, col2, i, j + 1, 0);
        }
    } else {
        // Move to next row
        multiplyRecursive(A, B, C, row1, col1, col2, i + 1, 0, 0);
    }
}

int main() {
    int row1, col1, row2, col2;

    cout << "Enter rows and cols of first matrix: ";
    cin >> row1 >> col1;

    cout << "Enter rows and cols of second matrix: ";
    cin >> row2 >> col2;

    if (col1 != row2) {
        cout << "Matrix multiplication not possible!" << endl;
        return 0;
    }

    int A[10][10], B[10][10], C[10][10] = {0};

    cout << "Enter first matrix:\n";
    for (int i = 0; i < row1; i++)
        for (int j = 0; j < col1; j++)
            cin >> A[i][j];

    cout << "Enter second matrix:\n";
    for (int i = 0; i < row2; i++)
        for (int j = 0; j < col2; j++)
            cin >> B[i][j];

    // Perform multiplication
    multiplyRecursive(A, B, C, row1, col1, col2);

    cout << "Resultant matrix:\n";
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }

    return 0;
}
