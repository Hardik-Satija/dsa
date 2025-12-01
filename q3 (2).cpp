#include <iostream>
using namespace std;
class Node {
    public:
    int data;
    Node* left;
    Node* right;
};
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
Node* insert(Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else
        cout << "Duplicate value " << value << " not inserted.\n";

    return root;
}
Node* findMin(Node* root) {
    while (root != NULL && root->left != NULL)
        root = root->left;
    return root;
}
Node* deleteNode(Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        else if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

int maxDepth(Node* root) {
    if (root == NULL)
        return 0;

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    if (leftDepth > rightDepth)
        return leftDepth + 1;
    else
        return rightDepth + 1;
}
int minDepth(Node* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL)
        return minDepth(root->right) + 1;
    if (root->right == NULL)
        return minDepth(root->left) + 1;

    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);

    if (leftDepth < rightDepth)
        return leftDepth + 1;
    else
        return rightDepth + 1;
}
void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main() {
    Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "In-order Traversal: ";
    inorder(root);
    cout << "\n";
    cout << "Deleting 20\n";
    root = deleteNode(root, 20);

    cout << "In-order after deletion: ";
    inorder(root);
    cout << "\n";
    cout << "Maximum Depth of BST: " << maxDepth(root) << "\n";
    cout << "Minimum Depth of BST: " << minDepth(root) << "\n";

    return 0;
}
