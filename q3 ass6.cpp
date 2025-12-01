#include <iostream>
using namespace std;
struct DNode { int data; DNode* next; DNode* prev; };
struct CNode { int data; CNode* next; };
int sizeDoubly(DNode* head) {
    int count = 0;
    while (head) { count++; head = head->next; }
    return count;
}
int sizeCircular(CNode* head) {
    if (!head) return 0;
    int count = 0;
    CNode* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}
int main() {
    cout << "Size functions for Doubly and Circular lists implemented.\n";
}
