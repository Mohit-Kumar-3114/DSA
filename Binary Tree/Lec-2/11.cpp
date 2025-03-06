// Right/Left view of a binary tree

#include <bits/stdc++.h>
using namespace std;




struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};




// Optimal O(n) and O(h)
void leftView(Node* root, vector<int>& v, int level){
    if(!root) return;
   if(level==v.size())v.push_back(root->data);
   leftView(root->left,v,level+1);
   leftView(root->right,v,level+1);
}




// Optimal O(n) and O(h)
void rightView(Node* root, vector<int>& v,int level){
if(!root) return;
   if(level==v.size())v.push_back(root->data);
   rightView(root->right,v,level+1);
   rightView(root->left,v,level+1);
}




int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(10);
    root->right->left = new Node(9);
    vector<int> result;
    leftView(root,result,0);
    cout << "Left view ";
    for(auto level: result){
        cout << level<<" ";
    }
    cout<<endl;
    vector<int> result2;
    rightView(root,result2,0);
    cout << "Right view ";
    for(auto level: result2){
        cout << level<<" ";
    }
    return 0;
}