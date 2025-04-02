// Binary search tree iterator

#include <bits/stdc++.h>
using namespace std;




struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};




// Optimal O(1) and O(h)
class BSTIterator {
    stack<Node *> myStack;

public:
    BSTIterator(Node* root) {
        pushAll(root);
    }

    int next() {
        Node *tmpNode = myStack.top();
        myStack.pop();
        pushAll(tmpNode->right);
        return tmpNode->val;   
    }

    bool hasNext() {
        return !myStack.empty(); 
    }

private:
    void pushAll(Node *node) {
        while (node != NULL) {
            myStack.push(node);
            node = node->left;
        }
    }
};




int main() {
    Node* root = new Node(7);
    root->left = new Node(3);
    root->right = new Node(15);
    root->right->left = new Node(9);
    root->right->right = new Node(20);
    BSTIterator iterator(root);
    while (iterator.hasNext()) {
        cout << iterator.next() << " ";
    }
    return 0;
}