#include <iostream>
using namespace std;
#define SIZE 5
class CircularQueue {
private:
    int arr[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = rear = -1;
    }
    bool isEmpty() {
        return (front == -1);
    }
    bool isFull() {
        return ((rear + 1) % SIZE == front);
    }
    void enqueue(int val) {
        if (isFull())
            cout << "Queue is Full!\n";
        else {
            if (front == -1)
                front = 0;
            rear = (rear + 1) % SIZE;
            arr[rear] = val;
            cout << val << " inserted.\n";
        }
    }
    void dequeue() {
        if (isEmpty())
            cout << "Queue is Empty!\n";
        else {
            cout << arr[front] << " deleted.\n";
            if (front == rear)
                front = rear = -1;
            else
                front = (front + 1) % SIZE;
        }
    }
    void peek() {
        if (isEmpty())
            cout << "Queue is Empty!\n";
        else
            cout << "Front element: " << arr[front] << "\n";
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << "\n";
    }
};
int main() {
    CircularQueue cq;
    int choice, val;
    do {
        cout << "\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            cq.enqueue(val);
            break;
        case 2:
            cq.dequeue();
            break;
        case 3:
            cq.peek();
            break;
        case 4:
            cq.display();
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
