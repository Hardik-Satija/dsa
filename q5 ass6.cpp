#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int val) { data = val; next = nullptr; }
};
bool isCircular(Node* head) {
    if (!head) return false;
    Node* temp = head->next;
    while (temp && temp != head)
        temp = temp->next;
    return (temp == head);
}
int main() {
    Node* head = new Node(10);
    Node* n2 = new Node(20);
    Node* n3 = new Node(30);
    head->next = n2;
    n2->next = n3;
    n3->next = head;
    cout << (isCircular(head) ? "List is Circular\n" : "List is not Circular\n");
}
