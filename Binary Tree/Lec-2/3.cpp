// Diameter of a binary tree 

#include <bits/stdc++.h>
using namespace std;




struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};




// Optimal O(n) and O(h)
int findMax(Node* root, int &diameter) {
    if (!root) return 0;
    int left = findMax(root->left,diameter);
    int right = findMax(root->right,diameter);
    diameter=max(diameter,left+right);
    return 1 + max(left, right);
}




int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(5);
    int diameter=0;
    findMax(root,diameter);
    cout<<"Diameter of binary tree : "<<diameter;
    return 0;
}
