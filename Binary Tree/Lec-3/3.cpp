// Maximum width of a binary tree 

#include <bits/stdc++.h>
using namespace std;




struct Node {
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};




// Optimal O(n) and O(h)
int widthOfBinaryTree(Node* root) {
    if (!root) {
        return 0;
    }
    long long ans = 0;
    queue<pair<Node*, long long>> q;
    q.push({root, 0});
    while (!q.empty()) {
        int size = q.size();
        long long  first,last=0;
        long long mini = q.front().second;
        for (int i = 0; i < size; i++) {
            long long  pos = q.front().second-mini;
            Node* node = q.front().first;
            q.pop();
            if (i == 0) {
                first = pos;
            }

            if (i == size - 1) {
                last = pos;
            } 

            if (node->left) {
                q.push({node->left, pos * 2 + 1});
            }

            if (node->right) {
                q.push({node->right, pos * 2 + 2});
            }
        }
        ans = max(ans, last - first + 1);
    }
    return ans;
    }





int main() {
    Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->right->left = new Node(0);
    root->right->right = new Node(8);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);
    int maxWidth = widthOfBinaryTree(root);
    cout << "Maximum width of the binary tree is: "
                        << maxWidth << endl;
    return 0;
}