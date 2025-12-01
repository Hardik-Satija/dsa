#include <iostream>
#include <queue>
using namespace std;
class Stack {
    queue<int> q1, q2;
public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    void pop() {
        if (q1.empty())
            cout << "Stack is empty!\n";
        else {
            cout << "Popped: " << q1.front() << "\n";
            q1.pop();
        }
    }
    void top() {
        if (q1.empty())
            cout << "Stack is empty!\n";
        else
            cout << "Top element: " << q1.front() << "\n";
    }
    bool empty() {
        return q1.empty();
    }
};
int main() {
    Stack s;
    int ch, val;
    do {
        cout << "\n1.Push\n2.Pop\n3.Top\n4.Exit\nEnter choice: ";
        cin >> ch;
        switch (ch) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            s.push(val);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.top();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (ch != 4);
    return 0;
}
