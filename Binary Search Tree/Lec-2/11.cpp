// Two sum in a binary search tree 

#include <bits/stdc++.h>
using namespace std;




struct Node {
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};




// Optimal O(n) and O(n)
void inorder(Node* root, vector<int>& ans){
    if(!root) return;
    inorder(root->left,ans);
    ans.push_back(root->val);
    inorder(root->right,ans);
}

bool isExists(Node* root, int sum){
vector<int>temp;
inorder(root,temp);
int i=0;
int j=temp.size()-1;
while(i<j){
    if(temp[i]+temp[j]==sum) return true;
    else if(temp[i]+temp[j]<sum) i++;
    else j--;
}
return false;
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
    if(isExists(root,91)) cout<<"Yes there is pair of given sum"<<endl;
    else cout<<"No pair exists for given sum"<<endl;
    return 0;
}