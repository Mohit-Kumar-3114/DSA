// Lowest common ancestor in a binary search tree

#include <bits/stdc++.h>
using namespace std;




struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};




// Optimal O(log n) and O(1)
Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    while (root) {
        if (root->val > p->val && root->val > q->val)
            root = root->left; // Move left if both p and q are smaller

        else if (root->val < p->val && root->val < q->val)
            root = root->right; // Move right if both p and q are greater

        else
            return root; // Found the split point (LCA)
    }
    return NULL;  
}




int main() {
    Node* root = new Node(6);
    root->left = new Node(2);
    root->right = new Node(8);
    root->left->left = new Node(0);
    root->left->right = new Node(4);
    root->right->left = new Node(7);
    root->right->right = new Node(9);
    root->left->right->left = new Node(3);
    root->left->right->right = new Node(5);
    Node* p = root->left;  // Node with value 2
    Node* q = root->left->right;  // Node with value 4
    Node* lca = lowestCommonAncestor(root, p, q);
    cout << "LCA of " << p->val << " and " << q->val << " is " << lca->val << endl;
    return 0;
}
