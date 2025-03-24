// Inorder successor/predecessor in a binary search tree

#include <bits/stdc++.h>
using namespace std;




struct Node {
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};




// Brute O(n) and O(h)
void findSuccessor(Node* root, int& ans, int val){
    if(!root) return;
    findSuccessor(root->left,ans,val);
    if(root->val>val and root->val<ans) ans=root->val;
    findSuccessor(root->right,ans,val);
}

void findPredecessor(Node* root, int& ans, int val) {
    if (!root) return;
    findPredecessor(root->left, ans, val);  
    if (root->val < val && root->val > ans) 
        ans = root->val;
    findPredecessor(root->right, ans, val); 
}




// Optimal O(log n) and O(1)
void findSuccessor2(Node* root, int &ans, int val){
    while (root) {
        if (root->val > val) {
            ans = root->val;
            root = root->left;
        } else {
            root = root->right;
        }
    }
}

void findPredecessor2(Node* root, int &ans, int val) {
    while (root) {
        if (root->val < val) {  
            ans = root->val;  
            root = root->right;
        } else {
            root = root->left;
        }
    }
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
    int successor=INT_MAX;
    int val=8;
    findSuccessor(root,successor,val);
    cout<<"Successor from brute approach: "<<successor<<endl;
    int successor2=INT_MAX;
    findSuccessor2(root,successor2,val);
    cout<<"Successor from optimal approach: "<<successor2<<endl;
    int predecessor = INT_MIN;
    findPredecessor(root, predecessor, val);
    cout << "Predecessor from brute approach: " <<predecessor<<endl;
    int predecessor2 = INT_MIN;
    findPredecessor2(root, predecessor2, val);
    cout << "Predecessor from optimal approach: " <<predecessor2<<endl;
    return 0;
}