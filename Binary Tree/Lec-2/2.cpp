// Check if binary tree is height balanced or not

#include <bits/stdc++.h>
using namespace std;




struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};




// Brute O(n^2) and O(h)
int height(Node* root){
    if(!root) return 0;
    return max(height(root->left),height(root->right))+1;
}

bool check_balanced(Node* root){
    if(!root) return true;
    int left=height(root->left);
    int right=height(root->right);
    if(abs(left-right)>1) return false;
    bool l=check_balanced(root->left);
    bool r=check_balanced(root->right);
    if(!left or !right) return false;
    return true;
}




// Optimal O(n) and O(h)
int checkHeight(Node* root) {
    if (!root) return 0;
    int left = checkHeight(root->left);
    if (left == -1) return -1;
    int right = checkHeight(root->right);
    if (right == -1) return -1;
    if (abs(left - right) > 1) return -1; 
    return 1 + max(left, right);
}

bool check_balanced2(Node* root) {
    return checkHeight(root) != -1;
}




int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(5);
    if(check_balanced(root))cout<<"Tree is balanced";
    else cout<< "Tree is not balanced";
    if(check_balanced2(root))cout<<"\nTree is balanced";
    else cout<< "\nTree is not balanced";
    return 0;
}
