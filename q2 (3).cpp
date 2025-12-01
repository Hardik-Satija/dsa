#include<iostream>
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
Node* insert(Node* root, int value) {
    if (root == nullptr)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}
Node* searchRecursive(Node* root,int key){
    if (root == nullptr || root->data == key)
        return root;
    if (key < root->data)
        return searchRecursive(root->left, key);
    else
        return searchRecursive(root->right, key);
};
Node* searchNonRecursive(Node* root,int key){
    while(root!=nullptr){
        if (root->data == key)
            return root;
        else if (key < root->data)
            root=root->left;
        else
            root=root->right;
    }
    return nullptr;
};
Node* minnode(Node* root){
    while (root->left!=nullptr){
        root=root->left;
    }
    return root;
};
Node* maxnode(Node* root){
    while (root->right!=nullptr){
        root=root->right;
    }
    return root;
};
Node* inorderSuccessor(Node* root, Node* node) {
    if (node == nullptr)
        return nullptr;
    if (node->right != nullptr)
        return minnode(node->right);

    Node* successor = nullptr;
    Node* ancestor = root;
    while (ancestor != node) {
        if (node->data < ancestor->data) {
            successor = ancestor;
            ancestor = ancestor->left;
        } else {
            ancestor = ancestor->right;
        }
    }
    return successor;
};
Node* inorderPredecessor(Node* root, Node* node) {
    if (node == nullptr)
        return nullptr;
    if (node->left != nullptr)
        return maxnode(node->left);

    Node* predecessor = nullptr;
    Node* ancestor = root;
    while (ancestor != node) {
        if (node->data > ancestor->data) {
            predecessor = ancestor;
            ancestor = ancestor->right;
        } else {
            ancestor = ancestor->left;
        }
    }
    return predecessor;
};
void inorderTraversal(Node* root) {
    if (root == nullptr)
        return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
};
int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);
    cout << "In-order Traversal: ";
    inorderTraversal(root);
    cout << "\n";
    int key = 40;
    Node* found = searchRecursive(root, key);
    cout << "\nSearching (Recursive) for " << key << ": "
         << (found ? "Found" : "Not Found");

    found = searchNonRecursive(root, key);
    cout << "\nSearching (Non-Recursive) for " << key << ": "
         << (found ? "Found" : "Not Found");
    cout << "\nMaximum Element: " << maxnode(root)->data;
    cout << "\nMinimum Element: " << minnode(root)->data;
    Node* node = searchRecursive(root, 50);
    Node* successor = inorderSuccessor(root, node);
    if (successor)
        cout << "\nIn-order Successor of " << node->data << ": " << successor->data;
    else
        cout << "\nNo In-order Successor for " << node->data;
    Node* predecessor = inorderPredecessor(root, node);
    if (predecessor)
        cout << "\nIn-order Predecessor of " << node->data << ": " << predecessor->data;
    else
        cout << "\nNo In-order Predecessor for " << node->data;

    cout << endl;
    return 0;
}
