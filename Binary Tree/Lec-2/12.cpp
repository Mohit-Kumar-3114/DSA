// Check for a symmetrical binary tree

#include <bits/stdc++.h>
using namespace std;




struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};




// Optimal O(n) and O(h)
bool isMirror(Node* leftSub, Node* rightSub) {
    if (leftSub == NULL && rightSub == NULL) return true;
    if (leftSub == NULL || rightSub == NULL) return false;
    return (leftSub->data == rightSub->data) &&
           isMirror(leftSub->left, rightSub->right) &&
           isMirror(leftSub->right, rightSub->left);
}

bool isSymmetric(Node* root) {
    if (!root) return true; 
    return isMirror(root->left, root->right);
}




int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(8);
    root->right->left = new Node(4);
    root->right->right = new Node(3);
    if (isSymmetric(root)) {
        cout << "The binary tree is symmetric (mirror of itself)." << endl;
    } else {
        cout << "The binary tree is NOT symmetric." << endl;
    }
    return 0;
}
