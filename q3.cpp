#include <iostream>
using namespace std;
#define SIZE 100
char st[SIZE];
int top = -1;
void push(char c) {
    if (top < SIZE - 1) st[++top] = c;
}
char pop() {
    if (top >= 0) return st[top--];
    return '\0';
}
bool match(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}
bool checkBalanced(string exp) {
    for (char c : exp) {
        if (c == '(' || c == '{' || c == '[') {
            push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (top == -1 || !match(pop(), c)) return false;
        }
    }
    return (top == -1);
}
int main() {
    string exp;
    cout << "Enter an expression: ";
    cin >> exp;
    if (checkBalanced(exp))
        cout << "Balanced Expression\n";
    else
        cout << "Not Balanced Expression\n";

    return 0;
}
