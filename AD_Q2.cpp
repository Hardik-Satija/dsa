#include <iostream>
#include <stack>
using namespace std;

class SpecialStack {
private:
    stack<pair<int, int>> st;

public:
    SpecialStack() {
    }
    
    void push(int x) {
        int newMin = st.empty() ? x : min(x, st.top().second);
        st.push({x, newMin});
    }
    
    void pop() {
        if (!st.empty()) {
            st.pop();
        }
    }
    
    int peek() {
        if (st.empty()) {
            return -1;
        }
        return st.top().first;
    }
    
    int getMin() {
        if (st.empty()) {
            return -1;
        }
        return st.top().second;
    }
};

int main() {
    SpecialStack st;
    st.push(2);
    st.push(3);
    cout << st.peek() << " ";
    st.pop();
    cout << st.getMin() << " ";
    st.push(1);
    cout << st.getMin() << " ";
}
