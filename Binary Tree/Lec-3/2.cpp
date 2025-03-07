// Lowest common ancestor 

#include <bits/stdc++.h>
using namespace std;




struct Node {
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};




// Optimal O(n) and O(h)
Node* lowestCommonAncestor(Node* root, int p, int q) {
    if (!root) return NULL;
    if(root->val==p or root->val==q) return root;
    Node* left = lowestCommonAncestor(root->left, p, q);
    Node* right = lowestCommonAncestor(root->right, p, q);

    if(left and right) {
        return root;
    }
    else if(left) {
        return left;
    }
    else { 
        return right;
    }
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
    int targetLeafValue = 7;
    cout<<"LCA is: "<<lowestCommonAncestor(root,6,4)->val;
    return 0;
}