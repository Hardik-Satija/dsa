#include <iostream>
using namespace std;
int main() {
    int n = 4;
    int A[50];   
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            int x; cin >> x;
            if(i-j==1) {
                A[i-2] = x;}
            else if(i-j==0) {
                A[n-1+i-1] = x;}    
            else if(i-j==-1) {
                A[2*n-1+i-1] = x;
            }   
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(i-j==1){ 
                cout << A[i-2] << " ";
            }
            else if(i-j==0){
                cout << A[n-1+i-1] << " ";
            }
            else if(i-j==-1){
                cout << A[2*n-1+i-1] << " ";}
            else {cout << "0 ";}
        }
        cout << endl;
    }
}
