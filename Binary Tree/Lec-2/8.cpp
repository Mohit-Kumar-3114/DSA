// Verticsl order traversal of a binary tree 
                         
#include <bits/stdc++.h>
using namespace std;




struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};




// Optimal O(n log n) and O(n)
vector<vector<int>> findVertical(Node* root){
        // Map to store nodes based on
        // vertical and level information
        // Multiset stores values in sorted order allow duplicates
        map<int, map<int, multiset<int>>> nodes;
        
        // Queue for BFS traversal, each
        // element is a pair containing node
        // and its vertical and level information
        queue<pair<Node*, pair<int, int>>> todo;
        todo.push({root, {0, 0}});
        
        // BFS traversal
        while(!todo.empty()){
            // Retrieve the node and its vertical
            // and level information from
            // the front of the queue
            auto p = todo.front();
            todo.pop();
            Node* temp = p.first;

            // x -> vertical
            int x = p.second.first;  
            // y -> level
            int y = p.second.second; 
            
            // Insert the node value into the
            // corresponding vertical and level
            // in the map
            nodes[x][y].insert(temp->data);
            
            // Process left child
            if(temp->left){
                todo.push({temp->left,{x-1, y+1}});
            }
            
            // Process right child
            if(temp->right){
                todo.push({temp->right,{x+1,y+1}});
            }
        }
        
        vector<vector<int>> ans;
        for(auto p: nodes){
            vector<int> col;
            for(auto q: p.second){
                // Insert node values
                // into the column vector
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            // Add the column vector
            // to the final result
            ans.push_back(col);
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
    vector<vector<int>> result =findVertical(root);
    cout << "Vertical Traversal: ";
    for(auto level: result){
        for(auto node: level){
            cout << node << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
                            
                        