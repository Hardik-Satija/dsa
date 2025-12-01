#include <iostream>
using namespace std;
#define MAX 5
int stack[MAX], top = -1;
void push(int x) {
    if (top == MAX - 1) {
        cout << "Stack Overflow! Cannot push " << x << endl;
        return;
    }
    stack[++top] = x;
    cout << x << " pushed into stack." << endl;
}
void pop() {
    if (top == -1) {
        cout << "Stack Underflow! Nothing to pop." << endl;
        return;
    }
    cout << stack[top--] << " popped from stack." << endl;
}
void peek() {
    if (top == -1) {
        cout << "Stack is empty! Nothing to peek." << endl;
        return;
    }
    cout << "Top element is: " << stack[top] << endl;
}
void display() {
    if (top == -1) {
        cout << "Stack is empty" << endl;
        return;
    }
    cout << "Stack elements: ";
    for (int i = 0; i <= top; i++) {
        cout << stack[i] << " ";
    }
    cout << endl;
}
void isEmpty() {
    if (top == -1)
        cout << "Stack is empty" << endl;
    else
        cout << "Stack is not empty" << endl;
}
void isFull() {
    if (top == MAX - 1)
        cout << "Stack is full" << endl;
    else
        cout << "Stack is not full" << endl;
}
int main() {
    int choice, value;
    do {
        cout << "\nStack Menu\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n5. Check if Empty\n6. Check if Full\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            isEmpty();
            break;
        case 6:
            isFull();
            break;
        case 7:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
