// Recover bst or correct bst with two swapped nodes

#include <bits/stdc++.h>
using namespace std;




struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};




// Optimal O(n) and O(h)
void inorder(Node* root, Node*& first, Node*& second, Node*& prev) {
    if (!root) return;
    inorder(root->left, first, second, prev);
    
    // Identify swapped nodes
    if (first == NULL && prev->val > root->val) {
        first = prev;
    }
    if (first != NULL && prev->val > root->val) {
        second = root;
    }
    prev = root;
    
    inorder(root->right, first, second, prev);
}

void recoverTree(Node* root) {
    Node *first = NULL, *second = NULL, *prev = new Node(INT_MIN);
    inorder(root, first, second, prev);
    if (first && second) swap(first->val, second->val);
}




void printInOrder(Node* root) {
    if (!root) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}




int main() {
    Node* root = new Node(6);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->left = new Node(7);
    root->right->right = new Node(10);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(12);
    
    // Swapping two nodes to create an error
    swap(root->left->val, root->left->left->val);
    cout << "Before recovery: ";
    printInOrder(root);
    cout << endl;
    recoverTree(root);
    cout << "After recovery: ";
    printInOrder(root);
    cout << endl;
    return 0;
}

