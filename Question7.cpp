#include <iostream>
using namespace std;
int main() {
    int A[10];
    cout << "Enter elements: ";
    for (int i = 0; i < 10; i++) {
        cin >> A[i];
    }

    int inv = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (A[i] > A[j]) {
                inv++;
            }
        }
    }
    cout << "Number of inversions: " << inv << endl;
    return 0;
}
