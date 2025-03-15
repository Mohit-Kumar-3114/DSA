// Construct a binary tree from inorder and preorder traversal
                   
#include <bits/stdc++.h>
using namespace std;




struct Node {
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};




// Optimal O(n) and O(n)
Node* buildTree(vector<int>& preorder, int& preIndex, int start, int end, unordered_map<int, int>& inMap) {
    if (start > end) return NULL;

    int rootVal = preorder[preIndex++];
    Node* root = new Node(rootVal);
    int mid = inMap[rootVal];

    root->left = buildTree(preorder, preIndex, start, mid - 1, inMap);
    root->right = buildTree(preorder, preIndex, mid + 1, end, inMap);

    return root;
}

Node* build(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> inMap;
    for (int i = 0; i < inorder.size(); i++) {
        inMap[inorder[i]] = i;
    }
    
    int preIndex = 0;
    return buildTree(preorder, preIndex, 0, inorder.size() - 1, inMap);
}




void printInorder(Node* root){
    if(!root){
        return;
    }
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}




int main() {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> preorder = {3, 9, 20, 15, 7};
    Node* root = build(preorder, inorder);
    cout << "Inorder of Unique Binary Tree Created: "<< endl;
    printInorder(root);
    cout << endl;
    return 0;
}
                            
                        