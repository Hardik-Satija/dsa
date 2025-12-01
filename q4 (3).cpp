#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k) : key(k), left(NULL), right(NULL) {}
};

bool isBSTUtil(Node* root, long long mn, long long mx) {
    if (!root) return true;
    if (root->key <= mn || root->key >= mx) return false;
    return isBSTUtil(root->left, mn, root->key) && isBSTUtil(root->right, root->key, mx);
}

bool isBST(Node* root) {
    return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
}

int main() {
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);
    bool ok = isBST(root);
    return 0;
}
