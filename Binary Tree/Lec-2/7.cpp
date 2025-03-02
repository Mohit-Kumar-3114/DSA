// Boundary order traversal of a binary tree

#include <bits/stdc++.h>
using namespace std;




struct Node {
    int data; 
    Node* left; 
    Node* right;
    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};




// Optimal O(n) and O(n)
bool isLeaf(Node* root) {
    return !root->left && !root->right;
}

void addLeftBoundary(Node* root, vector<int>& res) {
    Node* curr = root->left;
    while (curr) {
        if (!isLeaf(curr)) {
            res.push_back(curr->data);
        }
        // Move to the left child if it exists,
        // otherwise move to the right child
        if (curr->left) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
}

void addRightBoundary(Node* root, vector<int>& res) {
    Node* curr = root->right;
    vector<int> temp;
    while (curr) {
        if (!isLeaf(curr)) {
            temp.push_back(curr->data);
        }
        // Move to the right child if it exists,
        // otherwise move to the left child
        if (curr->right) {
            curr = curr->right;
        } else {
            curr = curr->left;
        }
    }
    for (int i = temp.size() - 1; i >= 0; i--) {
        res.push_back(temp[i]);
    }
}

void addLeaves(Node* root, vector<int>& res) {
    if (isLeaf(root)) {
        res.push_back(root->data);
        return;
    }
    if (root->left) {
        addLeaves(root->left, res);
    }
    if (root->right) {
        addLeaves(root->right, res);
    }
}




int main() {
Node* root = new Node(1);
root->left = new Node(2);
root->right = new Node(3);
root->left->left = new Node(4);
root->left->right = new Node(5);
root->right->left = new Node(6);
root->right->right = new Node(7);
vector<int> res;
if (!isLeaf(root)) {
        res.push_back(root->data);
}
    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);
cout << "Boundary Traversal: ";
for (int val : res) {
    cout << val << " ";
}
cout << endl;
return 0;
}