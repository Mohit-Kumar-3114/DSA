// Largest bst in a binary tree

#include <bits/stdc++.h>
using namespace std;




struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};




struct Info {
    int size;
    int minVal;
    int maxVal;
};




// Optimal O(n) and O(h)
Info largestBSTUtil(Node* root) {
    if (!root) return {0, INT_MAX, INT_MIN};
    
    Info left = largestBSTUtil(root->left);
    Info right = largestBSTUtil(root->right);
    if(left.maxVal < root->val && right.minVal > root->val) {
        // This is a BST
        return {left.size + right.size + 1, min(left.minVal, root->val), max(right.maxVal, root->val)};
    }   
    return {max(left.size, right.size), INT_MIN, INT_MAX}; // Not a BST    
}

int largestBST(Node* root) {
    return largestBSTUtil(root).size;
}




int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(1);
    root->left->right = new Node(8);
    root->right->right = new Node(7);
    cout << "Size of the largest BST in the given binary tree: " << largestBST(root) << endl;
    return 0;
}
