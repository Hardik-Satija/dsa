#include <iostream>
using namespace std;
#define SIZE 5
class Queue {
private:
    int arr[SIZE];
    int front, rear;
public:
    Queue() {
        front = -1;
        rear = -1;
    }
    bool isEmpty() {
        return (front == -1 || front > rear);
    }
    bool isFull() {
        return (rear == SIZE - 1);
    }
    void enqueue(int val) {
        if (isFull())
            cout << "Queue is Full!\n";
        else {
            if (front == -1) front = 0;
            arr[++rear] = val;
            cout << val << " inserted.\n";
        }
    }
    void dequeue() {
        if (isEmpty())
            cout << "Queue is Empty!\n";
        else {
            cout << arr[front] << " deleted.\n";
            front++;
        }
    }
    void peek() {
        if (isEmpty())
            cout << "Queue is Empty!\n";
        else
            cout << "Front element: " << arr[front] << "\n";
    }
    void display() {
        if (isEmpty())
            cout << "Queue is Empty!\n";
        else {
            cout << "Queue elements: ";
            for (int i = front; i <= rear; i++)
                cout << arr[i] << " ";
            cout << "\n";
        }
    }
};
int main() {
    Queue q;
    int choice, val;
    do {
        cout << "\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            q.enqueue(val);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.peek();
            break;
        case 4:
            q.display();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 5);
    return 0;
}
