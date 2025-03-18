// Ceil in a binary search tree

#include<bits/stdc++.h>
using namespace std;




struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};




// Optimal O(log n) and O(1)
int findCeil(Node* root, int input) {
    int ceil = -1; 
    while (root) {
        if (root->data == input) {
            ceil = root->data;
            return ceil;
        } 
        // If input is greater, move to the right
        if (root->data < input) {
            root = root->right;
        }
        // If input is smaller, update ceil and move left
        else { 
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
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
    int input = 17;
    int ceilVal = findCeil(root, input);
    cout << "Ceil value of " << input << " in BST: " << ceilVal << endl;
    return 0;
}
