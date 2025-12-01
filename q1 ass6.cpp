#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int val) { data = val; next = nullptr; }
};
class CircularLinkedList {
    Node* head;
public:
    CircularLinkedList() { head = nullptr; }
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
    void insertAfter(int key, int val) {
        if (!head) {
            cout << "List empty.\n";
            return;
        }
        Node* temp = head;
        do {
            if (temp->data == key) {
                Node* newNode = new Node(val);
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Key not found.\n";
    }
    void insertBefore(int key, int val) {
        if (!head) {
            cout << "List empty.\n";
            return;
        }
        if (head->data == key) {
            insertAtBeginning(val);
            return;
        }
        Node* prev = nullptr;
        Node* curr = head;
        do {
            if (curr->data == key) {
                Node* newNode = new Node(val);
                newNode->next = curr;
                prev->next = newNode;
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);
        cout << "Key not found.\n";
    }
    void deleteNode(int key) {
        if (!head) {
            cout << "List empty.\n";
            return;
        }
        Node *curr = head, *prev = nullptr;
        do {
            if (curr->data == key) {
                if (curr == head) {  // deleting head
                    Node* last = head;
                    while (last->next != head)
                        last = last->next;
                    if (head == head->next) {  // only one node
                        delete head;
                        head = nullptr;
                        return;
                    }
                    last->next = head->next;
                    Node* del = head;
                    head = head->next;
                    delete del;
                    return;
                } else {  // deleting middle or last node
                    prev->next = curr->next;
                    delete curr;
                    return;
                }
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);
        cout << "Key not found.\n";
    }
    void search(int key) {
        if (!head) {
            cout << "List empty.\n";
            return;
        }
        Node* temp = head;
        int pos = 1;
        do {
            if (temp->data == key) {
                cout << "Found at position " << pos << "\n";
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);
        cout << "Not found.\n";
    }
    void display() {
        if (!head) {
            cout << "List empty.\n";
            return;
        }
        Node* temp = head;
        cout << "Circular List: ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head)\n";
    }
};
class DNode {
public:
    int data;
    DNode* next;
    DNode* prev;
    DNode(int val) { data = val; next = prev = nullptr; }
};
class DoublyLinkedList {
    DNode* head;
public:
    DoublyLinkedList() { head = nullptr; }
    void insertAtBeginning(int val) {
        DNode* newNode = new DNode(val);
        if (head) {
            newNode->next = head;
            head->prev = newNode;
        }
        head = newNode;
    }
    void insertAtEnd(int val) {
        DNode* newNode = new DNode(val);
        if (!head) {
            head = newNode;
            return;
        }
        DNode* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
    void insertAfter(int key, int val) {
        DNode* temp = head;
        while (temp && temp->data != key)
            temp = temp->next;
        if (!temp) {
            cout << "Key not found.\n";
            return;
        }
        DNode* newNode = new DNode(val);
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next)
            temp->next->prev = newNode;
        temp->next = newNode;
    }
    void insertBefore(int key, int val) {
        if (!head) {
            cout << "List empty.\n";
            return;
        }
        if (head->data == key) {
            insertAtBeginning(val);
            return;
        }
        DNode* temp = head;
        while (temp && temp->data != key)
            temp = temp->next;
        if (!temp) {
            cout << "Key not found.\n";
            return;
        }
        DNode* newNode = new DNode(val);
        newNode->next = temp;
        newNode->prev = temp->prev;
        temp->prev->next = newNode;
        temp->prev = newNode;
    }
    void deleteNode(int key) {
        if (!head) {
            cout << "List empty.\n";
            return;
        }
        DNode* temp = head;
        while (temp && temp->data != key)
            temp = temp->next;
        if (!temp) {
            cout << "Key not found.\n";
            return;
        }
        if (temp->prev)
            temp->prev->next = temp->next;
        else
            head = temp->next;
        if (temp->next)
            temp->next->prev = temp->prev;
        delete temp;
    }
    void search(int key) {
        DNode* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == key) {
                cout << "Found at position " << pos << "\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Not found.\n";
    }
    void display() {
        DNode* temp = head;
        if (!temp) {
            cout << "List empty.\n";
            return;
        }
        cout << "Doubly List: ";
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};
int main() {
    CircularLinkedList cll;
    DoublyLinkedList dll;

    int choice, listType, val, key;
    do {
        cout << "\n=== MAIN MENU ===\n";
        cout << "1. Circular Linked List\n2. Doubly Linked List\n3. Exit\n";
        cout << "Enter choice: ";
        cin >> listType;
        if (listType == 3) break;
        cout << "\n1.Insert at Beginning\n2.Insert at End\n3.Insert Before\n4.Insert After\n"
             << "5.Delete Node\n6.Search Node\n7.Display\n8.Back to Main Menu\n";

        do {
            cout << "Enter choice: ";
            cin >> choice;
            if (listType == 1) {  // Circular
                switch (choice) {
                case 1: cout << "Enter value: "; cin >> val; cll.insertAtBeginning(val); break;
                case 2: cout << "Enter value: "; cin >> val; cll.insertAtEnd(val); break;
                case 3: cout << "Enter key and value: "; cin >> key >> val; cll.insertBefore(key, val); break;
                case 4: cout << "Enter key and value: "; cin >> key >> val; cll.insertAfter(key, val); break;
                case 5: cout << "Enter key to delete: "; cin >> key; cll.deleteNode(key); break;
                case 6: cout << "Enter value to search: "; cin >> key; cll.search(key); break;
                case 7: cll.display(); break;
                }
            } else if (listType == 2) {  // Doubly
                switch (choice) {
                case 1: cout << "Enter value: "; cin >> val; dll.insertAtBeginning(val); break;
                case 2: cout << "Enter value: "; cin >> val; dll.insertAtEnd(val); break;
                case 3: cout << "Enter key and value: "; cin >> key >> val; dll.insertBefore(key, val); break;
                case 4: cout << "Enter key and value: "; cin >> key >> val; dll.insertAfter(key, val); break;
                case 5: cout << "Enter key to delete: "; cin >> key; dll.deleteNode(key); break;
                case 6: cout << "Enter value to search: "; cin >> key; dll.search(key); break;
                case 7: dll.display(); break;
                }
            }
        } while (choice != 8);

    } while (listType != 3);
}
