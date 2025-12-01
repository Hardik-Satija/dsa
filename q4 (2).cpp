#include <iostream>
using namespace std;
#define INT_MIN_VALUE -999999
#define INT_MAX_VALUE 999999
class Node {
    public:
    int data;
    Node* left;
    Node* right;
};
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
bool isBSTUtil(Node* root, int minValue, int maxValue) {
    if (root == NULL)
        return true;
    if (root->data <= minValue || root->data >= maxValue)
        return false;
    return (isBSTUtil(root->left, minValue, root->data) &&
            isBSTUtil(root->right, root->data, maxValue));
}
bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN_VALUE, INT_MAX_VALUE);
}
void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root1 = createNode(4);
    root1->left = createNode(2);
    root1->right = createNode(6);
    root1->left->left = createNode(1);
    root1->left->right = createNode(3);
    root1->right->left = createNode(5);
    root1->right->right = createNode(7);
    cout << "In-order Traversal of Tree 1: ";
    inorder(root1);
    cout << "\n";
    if (isBST(root1))
        cout << "Tree 1 is a BST\n";
    else
        cout << "Tree 1 is NOT a BST\n";
    Node* root2 = createNode(5);
    root2->left = createNode(2);
    root2->right = createNode(8);
    root2->left->left = createNode(1);
    root2->left->right = createNode(9);
    cout << "\nIn-order Traversal of Tree 2: ";
    inorder(root2);
    cout << "\n";
    if (isBST(root2))
        cout << "Tree 2 is a BST\n";
    else
        cout << "Tree 2 is NOT a BST\n";
    return 0;
}
