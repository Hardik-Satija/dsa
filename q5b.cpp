#include <iostream>
#include <queue>
using namespace std;
class Stack {
    queue<int> q;
public:
    void push(int x) {
        int size = q.size();
        q.push(x);
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    void pop() {
        if (q.empty())
            cout << "Stack is empty!\n";
        else {
            cout << "Popped: " << q.front() << "\n";
            q.pop();
        }
    }
    void top() {
        if (q.empty())
            cout << "Stack is empty!\n";
        else
            cout << "Top element: " << q.front() << "\n";
    }
    bool empty() {
        return q.empty();
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
