// Reverse a linkedlist 

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

// Function to print linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}




// Optimal O(n) and O(1)
void reverseLL(Node* &head){
    Node* p=0;
    Node* c=head;
    Node* n;
    while(c){
        n=c->next;
        c->next=p;
        p=c;
        c=n;
    }
    head=p;
}




int main() {
    vector<int> arr = {2, 5, 8, 7, 9, 11, 14, 16};
    Node* head = convertArr2LL(arr);
    cout<<"Original ll : ";
    printLinkedList(head);
    cout<<"Reversed ll : ";
    reverseLL(head);
    printLinkedList(head);
    return 0;
}