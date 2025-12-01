#include <iostream>
using namespace std;
#define SIZE 100
char stack[SIZE];
int top = -1;
void push(char c) {
    stack[++top] = c;
}
char pop() {
    return stack[top--];
}
int main() {
    string infix, postfix = "";
    cout << "Enter Infix Expression: ";
    cin >> infix;
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        if (isalnum(c)) {
            postfix += c;
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (top != -1 && stack[top] != '(')
                postfix += pop();
            top--;
        }
        else {
            int precC;
            if (c == '^') precC = 3;
            else if (c == '*' || c == '/') precC = 2;
            else precC = 1;

            int p;
            while (top != -1) {
                if (stack[top] == '^') p = 3;
                else if (stack[top] == '*' || stack[top] == '/') p = 2;
                else if (stack[top] == '+' || stack[top] == '-') p = 1;
                else p = 0;
                if (p >= precC)
                    postfix += pop();
                else
                    break;
            }
            push(c);
        }
    }
    while (top != -1) postfix += pop();
    cout << "Postfix Expression: " << postfix << endl;
    return 0;
}
