// Check if a binary tree is a binary search tree or not

#include <bits/stdc++.h>
using namespace std;




struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};




// Optimal O(n) and O(h)
bool isValidBST(Node* root, long minVal, long maxVal) {
    if (root == NULL) return true;
    
    if (root->val >= maxVal || root->val <= minVal) return false;
    
    return isValidBST(root->left, minVal, root->val) && isValidBST(root->right, root->val, maxVal);
}




int main() {
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);
    if (isValidBST(root, LONG_MIN, LONG_MAX)) // to avoid overflow
        cout << "The tree is a BST" << endl;
    else
        cout << "The tree is not a BST" << endl;
    return 0;
}
