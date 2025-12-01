#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};
class LinkedList {
    Node* head;
public:
    LinkedList() { head = nullptr; }
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }
    void insertBefore(int key, int val) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        if (head->data == key) {
            insertAtBeginning(val);
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != key)
            temp = temp->next;
        if (temp->next == nullptr)
            cout << "Key not found.\n";
        else {
            Node* newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    void insertAfter(int key, int val) {
        Node* temp = head;
        while (temp != nullptr && temp->data != key)
            temp = temp->next;
        if (temp == nullptr)
            cout << "Key not found.\n";
        else {
            Node* newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    void deleteFromBeginning() {
        if (head == nullptr)
            cout << "List is empty.\n";
        else {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void deleteFromEnd() {
        if (head == nullptr)
            cout << "List is empty.\n";
        else if (head->next == nullptr) {
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            while (temp->next->next != nullptr)
                temp = temp->next;
            delete temp->next;
            temp->next = nullptr;
        }
    }
    void deleteSpecific(int key) {
        if (head == nullptr)
            cout << "List is empty.\n";
        else if (head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            Node* temp = head;
            while (temp->next != nullptr && temp->next->data != key)
                temp = temp->next;
            if (temp->next == nullptr)
                cout << "Key not found.\n";
            else {
                Node* delNode = temp->next;
                temp->next = temp->next->next;
                delete delNode;
            }
        }
    }
    void search(int key) {
        Node* temp = head;
        int pos = 1;
        while (temp != nullptr) {
            if (temp->data == key) {
                cout << "Element found at position " << pos << "\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Element not found.\n";
    }
    void display() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};
int main() {
    LinkedList list;
    int choice, val, key;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert Before\n4. Insert After\n";
        cout << "5. Delete from Beginning\n6. Delete from End\n7. Delete Specific Node\n";
        cout << "8. Search\n9. Display\n10. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            list.insertAtBeginning(val);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> val;
            list.insertAtEnd(val);
            break;
        case 3:
            cout << "Enter key and value: ";
            cin >> key >> val;
            list.insertBefore(key, val);
            break;
        case 4:
            cout << "Enter key and value: ";
            cin >> key >> val;
            list.insertAfter(key, val);
            break;
        case 5:
            list.deleteFromBeginning();
            break;
        case 6:
            list.deleteFromEnd();
            break;
        case 7:
            cout << "Enter key to delete: ";
            cin >> key;
            list.deleteSpecific(key);
            break;
        case 8:
            cout << "Enter value to search: ";
            cin >> key;
            list.search(key);
            break;
        case 9:
            list.display();
            break;
        case 10:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 10);
    return 0;
}
