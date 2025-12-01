//Write program using functions for binary tree traversals: Pre-order, In-order and Post-
//order using recursive approach.
#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node *right;
};
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
};
void inorderTraversal(Node* root) {
    if (root == nullptr){
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
};
void preorderTraversal(Node* root){
      if (root == nullptr)
        return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void postorderTraversal(Node* root){
      if (root == nullptr)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
};
int main(){
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);
    cout << "In-order Traversal: ";
    inorderTraversal(root);
    cout << endl;
    cout << "Pre-order Traversal: ";
    preorderTraversal(root);
    cout << endl;
    cout << "Post-order Traversal: ";
    postorderTraversal(root);
    cout << endl;
    return 0;
}