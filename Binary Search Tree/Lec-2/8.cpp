// Construct a binary search tree from preorder traversal

#include <bits/stdc++.h>
using namespace std;




struct Node {
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};




// Brute O(n log n) and O(n)
Node* buildBST(vector<int>& preorder, int& preIndex, int start, int end, unordered_map<int, int>& inMap) {
    if (start > end) return NULL;

    int rootVal = preorder[preIndex++];
    Node* root = new Node(rootVal);
    int mid = inMap[rootVal];

    root->left = buildBST(preorder, preIndex, start, mid - 1, inMap);
    root->right = buildBST(preorder, preIndex, mid + 1, end, inMap);

    return root;
}

Node* build(vector<int>& preorder) {
    vector<int>inorder=preorder;
    sort(inorder.begin(),inorder.end()); // inorder of bst is always sorted 
    unordered_map<int, int> inMap;
    for (int i = 0; i < inorder.size(); i++) {
        inMap[inorder[i]] = i;
    }
    
    int preIndex = 0;
    return buildBST(preorder, preIndex, 0, inorder.size() - 1, inMap);
}




// Optimal O(n) and O(n)
Node* buildBST2(vector<int>& preorder, int& index, int minVal, int maxVal) {
    if (index == preorder.size() || preorder[index] < minVal || preorder[index] > maxVal) return nullptr;

    int val = preorder[index++]; // index-- for postorder
    Node* root = new Node(val);
    root->left = buildBST2(preorder, index, minVal, val); // root->right comes first in postorder
    root->right = buildBST2(preorder, index, val, maxVal);
    return root;
}

Node* build2(vector<int>& preorder) {
    int index = 0; // index=preorder.size()-1 in postorder
    return buildBST2(preorder, index, INT_MIN, INT_MAX);
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
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    Node* root1 = build(preorder);
    cout << "Inorder of BST created using O(n log n) method:" << endl;
    printInorder(root1);
    cout << endl;
    Node* root2 = build2(preorder);
    cout << "Inorder of BST created using O(n) method:" << endl;
    printInorder(root2);
    cout << endl;
    return 0;
}
                            
        