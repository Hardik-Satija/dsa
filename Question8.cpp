#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int A[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    int distinctCount = 0;
    for (int i = 0; i < n; i++) {
        int isD = 1; 
        for (int j = 0; j < i; j++) {
            if (A[i] == A[j]) {
                isD= 0; 
                break;
            }
        }
        if (isD == 1) {
            distinctCount++;
        }
    }
    cout << "Total number of distinct elements: " << distinctCount << endl;
    return 0;
}
