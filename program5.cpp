#include<iostream>
using namespace std;

int main() {
    int A[3][3] = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};
    cout << "Sum of each row:\n";
    for(int i = 0; i < 3; i++) {
        int rSum = 0;
        for(int j = 0; j < 3; j++) {
            rSum += A[i][j];
        }
        cout << "Row " << i + 1 << ": " << rSum << endl;
    }

    cout << "\nSum of each column:\n";
    for(int j = 0; j < 3; j++) {
        int cSum = 0;
        for(int i = 0; i < 3; i++) {
            cSum += A[i][j];
        }
        cout << "Column " << j + 1 << ": " << cSum << endl;
    }

    return 0;
}
