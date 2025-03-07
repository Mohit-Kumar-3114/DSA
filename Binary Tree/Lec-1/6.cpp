// Count all nodes in a binary tree 

#include <bits/stdc++.h>
using namespace std;




struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};




// Optimal O(n) and O(h)
int fn(Node* root){
    if(!root) return 0;
    return fn(root->left)+fn(root->right)+1;
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
    cout<<"No. of nodes are: "<<fn(root);
    return 0;
}