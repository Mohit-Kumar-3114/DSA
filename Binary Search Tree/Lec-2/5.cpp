// Kth smallest/largest element in a binary search tree

#include <bits/stdc++.h>
using namespace std;




struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};




// Optimal O(n) and O(h)
void inorder(Node* root, int& k, int& result) {
    if (root == NULL || k == 0) return;
    
    inorder(root->left, k, result);
    k--;
    if (k == 0) {
        result = root->val;
        return;
    }
    inorder(root->right, k, result);
}

int kthSmallest(Node* root, int k) {
    int result = -1;
    inorder(root, k, result);
    return result;
}




// Optimal O(n) and O(1)
void reverseInorder(Node* root, int& k, int& result) {
    if (root == NULL || k == 0) return;
    reverseInorder(root->right, k, result);
    k--;
    if (k == 0) {
        result = root->val;
        return;
    }
    reverseInorder(root->left, k, result);
}

int kthLargest(Node* root, int k) {
    int result = -1;
    reverseInorder(root, k, result);
    return result;
}




int main() {
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);
    int k = 3;
    cout << "The " << k << "rd smallest element is: " << kthSmallest(root, k) << endl;
    cout << "The " << k << "rd largest element is: " << kthLargest(root, k) << endl;
    return 0;
}
