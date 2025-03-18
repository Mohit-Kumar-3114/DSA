// Min/max value in a binary search tree

#include<bits/stdc++.h>
using namespace std;




struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};




// Optimal O(log n) and O(1)
int minValue(Node* root) {
    Node* temp = root;
    while (true) {
        if (temp->left) temp = temp->left;
        else return temp->data;
    }
    return -1; 
}




// Optimal O(log n) and O(1)
int maxValue(Node* root) {
    Node* temp = root;
    while (true) {
        if (temp->right) temp = temp->right;
        else return temp->data;
    }
    return -1;
}




int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    int minVal = minValue(root);
    cout << "Minimum value in BST: " << minVal << endl;
    int maxVal = maxValue(root);
    cout << "Maximum value in BST: " << maxVal << endl;
    return 0;
}
