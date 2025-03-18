// Insert a node in a binary search tree

#include<bits/stdc++.h>
using namespace std;




struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};




// Optimal O(log n) and O(1)
Node* insertIntoBST(Node* root, int data) {
    if (!root) return new Node(data);
    Node* temp = root;
    while (true) {
        if (temp->data < data) {
            if (temp->right) temp = temp->right;
            else {
                temp->right = new Node(data);
                break;
            }
        } else {
            if (temp->left) temp = temp->left;
            else {
                temp->left = new Node(data);
                break;
            }
        }
    }
    return root;
}




int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->right->left = new Node(15);
    root->right->right = new Node(25);
    root->left->left->left = new Node(1);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(9);
    root->right->left->left = new Node(12);
    root->right->left->right = new Node(18);
    root->right->right->right = new Node(30);
    int newValue = 17;
    root = insertIntoBST(root, newValue);
    cout << "Inserted " << newValue << " into BST." << endl; 
    return 0;
}
