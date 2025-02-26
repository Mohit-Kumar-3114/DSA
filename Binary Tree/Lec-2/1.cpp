// Height of a binary tree

#include <bits/stdc++.h>
using namespace std;




struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};




// Optimal O(n) and O(h)
int height(Node* root){
    if(!root) return 0;
    return max(height(root->left),height(root->right))+1;
}




int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(5);
    cout<<"Height of tree is : "<<height(root)<<endl;
    return 0;
}
