#include <iostream>
using namespace std;

int main() {
    int A[10][3] = {{3, 3, 3},{0, 2, 5},{1, 0, 7},{2, 1, 8}};
    int AT[10][3];
    AT[0][0] = A[0][1];
    AT[0][1] = A[0][0];
    AT[0][2] = A[0][2];
    int k = 1;
    for (int c = 0; c < A[0][1]; c++) {
        for (int i = 1; i <= A[0][2]; i++) {
            if (A[i][1] == c) {
                AT[k][0] = A[i][1];
                AT[k][1] = A[i][0];
                AT[k][2] = A[i][2];
                k++;
            }
        }
    }
    cout << "Transpose of A (Triplet):\n";
    for (int i = 0; i <= AT[0][2]; i++) {
        cout << AT[i][0] << " " << AT[i][1] << " " << AT[i][2] << endl;
    }
    return 0;
}
