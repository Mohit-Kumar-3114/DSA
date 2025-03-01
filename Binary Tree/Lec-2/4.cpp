// Maximum path sum in binary tree

#include <bits/stdc++.h>
using namespace std;




struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};




// Optimal O(n) and O(h)
int findMaxSum(Node* root, int &sum) {
    if (!root) return 0;
    int left = max(0,findMaxSum(root->left,sum));
    int right = max(0,findMaxSum(root->right,sum));
    sum=max(sum,left+right+root->data);
    return max(left, right)+root->data;
}




int main(){
    Node* root = new Node(-10);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);
    int sum=INT_MIN;
    findMaxSum(root,sum);
    cout<<"Sum of binary tree : "<<sum;
    return 0;
}
