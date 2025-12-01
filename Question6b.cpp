#include <iostream>
using namespace std;
int main() {
    int A[100][3] = {{3, 3, 3},{0, 1, 2},{1, 2, 3},{2, 0, 1}};
    int B[100][3] = {{3, 3, 3},{0, 0, 4},{1, 1, 5},{2, 2, 6}};
    int C[100][3];
    int i = 1, j = 1, k = 1;
    C[0][0] = A[0][0];
    C[0][1] = A[0][1];
    while (i <= A[0][2] && j <= B[0][2]) {
        if (A[i][0] < B[j][0] || (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2];
            i++; k++;
        } else if (B[j][0] < A[i][0] || (A[i][0] == B[j][0] && B[j][1] < A[i][1])) {
            C[k][0] = B[j][0];
            C[k][1] = B[j][1];
            C[k][2] = B[j][2];
            j++; k++;
        } else {
            int sum = A[i][2] + B[j][2];
            if (sum != 0) {
                C[k][0] = A[i][0];
                C[k][1] = A[i][1];
                C[k][2] = sum;
                k++;
            }
            i++; j++;
        }
    }
    while (i <= A[0][2]) {
        C[k][0] = A[i][0]; C[k][1] = A[i][1]; C[k][2] = A[i][2];
        i++; k++;
    }
    while (j <= B[0][2]) {
        C[k][0] = B[j][0]; C[k][1] = B[j][1]; C[k][2] = B[j][2];
        j++; k++;
    }
    C[0][2] = k - 1;

    cout << "A + B (Triplet):\n";
    for (int x = 0; x <= C[0][2]; x++) {
        cout << C[x][0] << " " << C[x][1] << " " << C[x][2] << endl;
    }
    return 0;
}
