#include <iostream>
using namespace std;
#define SIZE 100
int stack[SIZE];
int top = -1;
void push(int x) {
    stack[++top] = x;
}
int pop() {
    return stack[top--];
}
int main() {
    string postfix;
    cout << "Enter Postfix Expression: ";
    cin >> postfix;
    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];
        if (isdigit(c)) {
            push(c - '0');
        }
        else {
            int val2 = pop();
            int val1 = pop();
            int res;
            switch (c) {
                case '+': res = val1 + val2; break;
                case '-': res = val1 - val2; break;
                case '*': res = val1 * val2; break;
                case '/': res = val1 / val2; break;
            }
            push(res);
        }
    }
    cout << "Result: " << pop() << endl;
    return 0;
}
