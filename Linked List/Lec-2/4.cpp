// Reverse a doubly linked list

#include <bits/stdc++.h>
using namespace std; 




class Node {
public:
    int data;
    Node* next;
    Node* back;

    // Constructors
    Node(int data1, Node* next1 , Node* back1) {
        data = data1;
        next = next1;
        back=back1;
    }
    Node(int data1) {
        data = data1;
        next = nullptr;
        back= nullptr;
    }
};

// Function to convert an array to a linked list
Node* convertArr2LL(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        temp->back=mover;
        mover->next = temp;
        mover = temp;
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
void reverse(Node* &head){
    Node* p=0;
    Node* c=head;
    Node* n;
    while(c){
        n=c->next;
        c->next=p;
        c->back=n;
        p=c;
        c=n;
    }
    head=p;
}



int main() {
    vector<int> arr = {2, 5, 7, 8, 9, 11, 14, 16};
    Node* head = convertArr2LL(arr);
    cout << "Original Linked List: ";
    printLinkedList(head);
    reverse(head);
    cout <<"After reversing: ";
    printLinkedList(head);
    return 0;
}
