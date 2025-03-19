// Delete a node in a binary search tree

#include <bits/stdc++.h>
using namespace std;




struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};




// Optimal O(log n) and O(1)
Node* findLastRight(Node* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

Node* helper(Node* root) {
    if (root->left == NULL) return root->right;
    if (root->right == NULL) return root->left;
    
    Node* rightChild = root->right;
    Node* lastRight = findLastRight(root->left);
    lastRight->right = rightChild;
    return root->left;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL) return NULL;
    if(root->val==key) return helper(root);
    Node* dummy = root; 
    
    while (root != NULL) {
        if (root->val > key) { // Move left
            if (root->left != NULL && root->left->val == key) {
                root->left = helper(root->left);
                break;
            } else {
                root = root->left;
            }
        } else if (root->val < key) { // Move right
            if (root->right != NULL && root->right->val == key) {
                root->right = helper(root->right);
                break;
            } else {
                root = root->right;
            }
        }
    }
    return dummy; 
}




void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}




int main() {
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);
    cout << "Inorder before deletion: ";
    inorder(root);
    cout << endl;
    root = deleteNode(root, 50);
    cout << "Inorder after deletion: ";
    inorder(root);
    cout << endl;
    return 0;
}
