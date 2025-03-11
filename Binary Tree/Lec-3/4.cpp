// Children sum property in a binary tree 

#include <bits/stdc++.h>
using namespace std;




struct Node {
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};




// Optimal O(n) and O(h)
void changeTree(Node* root) {
    if (root == NULL) {
        return;
    }

    // Calculate the sum of the values of the left and right children, if they exist.
    int child = 0;
    if (root->left) {
        child += root->left->val;
    }
    if (root->right) {
        child += root->right->val;
    }

    // Compare the sum of children with the current node's value and update
    if (child >= root->val) {
        root->val = child;
    } else {
        // If the sum is smaller, update the child with the current node's value.
        if (root->left) {
            root->left->val = root->val;
        } else if (root->right) {
            root->right->val = root->val;
        }
    }

    // Recursively call the function on the left and right children.
    changeTree(root->left);
    changeTree(root->right);

    // Calculate the total sum of the values of the left and right children, if they exist.
    int tot = 0;
    if (root->left) {
        tot += root->left->val;
    }
    if (root->right) {
        tot += root->right->val;
    }

    // if it is not leaf node update root
    if (root->left or root->right) {
        root->val = tot;
    }
}




void inorder(Node* root){
    if(root == nullptr){
        return;
    }
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}




int main() {
    Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->right->left = new Node(0);
    root->right->right = new Node(8);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);
    inorder(root);
    changeTree(root);
    cout<<endl;
    inorder(root);
    return 0;
}