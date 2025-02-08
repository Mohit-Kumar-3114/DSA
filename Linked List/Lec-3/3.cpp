// Detect loop in a linked list

#include <bits/stdc++.h>
using namespace std; 




class Node {
public:
    int data;
    Node* next;

    // Constructors
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Function to convert an array to a linked list
Node* convertArr2LL(vector<int>& arr) {
    if (arr.empty()) return nullptr; 
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size(); i++) {
        mover->next = new Node(arr[i]);
        mover = mover->next;
    }
    return head;
}




// Optimal O(n) and O(1)
bool detectCycle(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) return true;
    } return false;
}



int main() {
    vector<int> arr = {2, 5, 8, 7, 9, 11, 14, 16};
    Node* head = convertArr2LL(arr);
    if(detectCycle(head)) cout<< "There is loop in ll";
    else cout<< "There is no loop in ll";
    return 0;
}