#include <iostream>
using namespace std;
int main() {
    int n = 4;              
    int A[10];              
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            int x;
            cin >> x;
            if(i==j) A[i-1] = x; 
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(i==j) cout << A[i-1] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
}
