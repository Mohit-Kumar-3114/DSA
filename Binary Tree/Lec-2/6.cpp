// Zig-zag order traversal of a binary tree

#include <bits/stdc++.h>
using namespace std;




struct Node {
    int val; 
    Node* left; 
    Node* right;
    Node(int d) : val(d), left(nullptr), right(nullptr) {}
};




// Optimal O(n) and O(n)
vector<vector<int>> zigZagOrder(Node* root) {
        vector<vector<int>> ans; 
        if (root == nullptr) {
            return ans; 
        }
        queue<Node*> q; 
        q.push(root); 
        bool flag=true;
        while (!q.empty()) {
            int size = q.size(); 
            vector<int> level; 
            for (int i = 0; i < size; i++) {
                Node* node = q.front(); 
                q.pop(); 
                level.push_back(node->val); 
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            if (!flag) {
                reverse(level.begin(), level.end());
            }
            ans.push_back(level); 
            flag = !flag;
        }
        return ans; 
}




int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    vector<vector<int>> result = zigZagOrder(root); 
    cout << "Zig-zag Order Traversal of Tree: "<< endl;
    for (const vector<int>& level : result) {
        for (int num : level) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}