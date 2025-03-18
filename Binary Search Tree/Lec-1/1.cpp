// Search in a binary search tree 

#include<bits/stdc++.h>
using namespace std;




struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};




// Optimal O(log n) and O(1)
Node* searchBST(Node* root, int data) {
    Node* temp = root;
    while (temp) {
        if (temp->data == data) return temp;
        else if (temp->data < data) temp = temp->right;
        else temp = temp->left;
    }
    return NULL;
}




int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    int searchData = 9;
    Node* result = searchBST(root, searchData);
    if (result) {
        cout << "Value found: " << result->data << endl;
    } else {
        cout << "Value not found in BST." << endl;
    }
    return 0;
}
