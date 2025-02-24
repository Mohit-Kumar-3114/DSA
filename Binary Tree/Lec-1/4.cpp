// Level order traversal in binary tree
                            
#include <bits/stdc++.h>
using namespace std;




struct Node {
    int val; 
    Node* left; 
    Node* right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node* left, Node* right) : val(x), left(left), right(right) {}
};




// Optimal O(n) and O(n)
vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans; 
        if (root == nullptr) {
            return ans; 
        }
        queue<Node*> q; 
        q.push(root); 
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
            ans.push_back(level); 
        }
        return ans; 
}




int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    vector<vector<int>> result = levelOrder(root); 
    cout << "Level Order Traversal of Tree: "<< endl;
    for (const vector<int>& level : result) {
        for (int num : level) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
                            
                        