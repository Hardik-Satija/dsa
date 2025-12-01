#include <iostream>
using namespace std;
#define MAX 100  
char stack[MAX];
int top = -1;
void push(char c) {
    if (top == MAX - 1) {
        cout << "Stack Overflow!" << endl;
        return;
    }
    stack[++top] = c;
}
char pop() {
    if (top == -1) {
        cout << "Stack Underflow!" << endl;
        return '\0';
    }
    return stack[top--];
}
int main() {
    string str = "DataStructure";
    string reversed = "";

    for (int i = 0; i < str.length(); i++) {
        push(str[i]);
    }

    while (top != -1) {
        reversed += pop();
    }
    cout << "Original String: " << str << endl;
    cout << "Reversed String: " << reversed << endl;
    return 0;
}
