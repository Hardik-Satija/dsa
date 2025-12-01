#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;
    int A[n], G[n];
    for(int i = 0; i < n; i++) cin >> A[i];

    stack<int> st;

    for(int i = 0; i < n; i++) {
        while(!st.empty() && st.top() >= A[i]) st.pop();
        if(st.empty()) G[i] = -1;
        else G[i] = st.top();
        st.push(A[i]);
    }

    for(int i = 0; i < n; i++) {
        cout << G[i] << " ";
    }
}
