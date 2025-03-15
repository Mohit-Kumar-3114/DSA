// Construct a binary tree from inorder and postorder traversal
                   
#include <bits/stdc++.h>
using namespace std;




struct Node {
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};




// Optimal O(n) and O(n)
Node* buildTree(vector<int>& postorder, int& postIndex, int start, int end, unordered_map<int, int>& inMap) {
    if (start > end) return NULL;
    int rootVal = postorder[postIndex--];
    Node* root = new Node(rootVal);
    int mid = inMap[rootVal];
    root->right = buildTree(postorder, postIndex, mid + 1, end, inMap);
    root->left = buildTree(postorder, postIndex, start, mid - 1, inMap);
    return root;
}

Node* build(vector<int>& postorder, vector<int>& inorder) {
    unordered_map<int, int> inMap;
    for (int i = 0; i < inorder.size(); i++) {
        inMap[inorder[i]] = i;
    }
    
    int postIndex = postorder.size()-1;
    return buildTree(postorder, postIndex, 0, inorder.size() - 1, inMap);
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
    vector<int> inorder = {40, 20, 50, 10, 60, 30};
    vector<int> postorder = {40, 50, 20, 60, 30, 10};
    Node* root = build(postorder, inorder);
    cout << "Inorder of Unique Binary Tree Created: "<< endl;
    printInorder(root);
    cout << endl;
    return 0;
}
                            
                        