// Print root to node path in a binary tree
                          
#include <bits/stdc++.h>
using namespace std;




struct Node {
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};




// Optimal O(n) and O(h)
bool getPath(Node* root, vector<int>& arr, int x) {
    if (!root) {
        return false;
    }
    arr.push_back(root->val);
    if (root->val == x) {
        return true;
    }
    if (getPath(root->left, arr, x)
        || getPath(root->right, arr, x)) {
        return true;
    }
    arr.pop_back();
    return false;
}

vector<int> solve(Node* A, int B) {
    vector<int> arr;
    if (A == NULL) {
            return arr;
     }
        getPath(A, arr, B);
        return arr;
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
    int targetLeafValue = 7;
    vector<int> path = solve(root, targetLeafValue);
    cout << "Path from root to leaf with value " <<
        targetLeafValue << ": ";
    for (int i = 0; i < path.size(); ++i) {
        cout << path[i];
        if (i < path.size() - 1) {
            cout << " -> ";
        }
    }

    return 0;
}
                            
                        