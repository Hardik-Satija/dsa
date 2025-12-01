#include <iostream>
using namespace std;
class Node {
public:
    char data;
    Node* next;
    Node* prev;
    Node(char c) { data = c; next = prev = nullptr; }
};
bool isPalindrome(Node* head) {
    if (!head) return true;
    Node* tail = head;
    while (tail->next) tail = tail->next;

    while (head && tail && head != tail && tail->next != head) {
        if (head->data != tail->data)
            return false;
        head = head->next;
        tail = tail->prev;
    }
    return true;
}
int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;
    Node* head = nullptr;
    Node* tail = nullptr;
    for (char c : s) {
        Node* newNode = new Node(c);
        if (!head) head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    cout << (isPalindrome(head) ? "Palindrome\n" : "Not Palindrome\n");
}
