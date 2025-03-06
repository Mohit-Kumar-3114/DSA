// Bottom view of a binary tree 

#include <bits/stdc++.h>
using namespace std;




struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};




// Optimal O(n log n) and O(n)
vector<int> bottomView(Node* root){
        map<int,int> nodes;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        
        // BFS traversal
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            Node* temp = p.first;
            int x=p.second;
            nodes[x]=temp->data;
            if(temp->left){
                q.push({temp->left,x-1});
            }
            if(temp->right){
                q.push({temp->right,x+1});
            }
        }
        
        vector<int> ans;
        for(auto& p: nodes){
         ans.push_back(p.second);
        }
        return ans;
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
    vector<int> result =bottomView(root);
    cout << "Bottom view ";
    for(auto level: result){
        cout << level<<" ";
    }
    return 0;
}
        