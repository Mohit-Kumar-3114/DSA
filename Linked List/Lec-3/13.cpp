// Add 1 to a linked list 

#include <bits/stdc++.h>
using namespace std;




class Node {
    public:
        int data;
        Node* next;
        
        Node(int val) {
            data = val;
            next = nullptr;
        }
};    

// Function to print a linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}




// Brute O(3n) and O(1)
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

Node* add1ToLL(Node * head){
reverseLL(head);
Node* temp=head;
int carry=1;
while(temp){
 temp->data=temp->data+carry;
 if(temp->data < 10){
    carry=0;
    break;
 }
 else{
    temp->data=0;
 }
 temp=temp->next;
}
reverseLL(head);
if(carry==1){
    Node* n=new Node(1);
    n->next=head;
    return n;
} 
return head;
}




// Optimal O(n) and O(n)
int helper(Node* temp){
if(!temp) return 1;
int carry=helper(temp->next);
temp->data=temp->data+carry;
if(temp->data < 10) return 0;
else{
    temp->data=0;
    return 1;
} 
}

Node* add1ToLL2(Node * head){
int carry=helper(head);
if(carry==1){
    Node* n=new Node(1);
    n->next=head;
    return n;
} 
return head;
}




int main() {
    Node* head = new Node(9);
    head->next = new Node(9);
    head->next->next = new Node(9);
    head->next->next->next = new Node(9);
    head->next->next->next->next = new Node(9);
    head->next->next->next->next->next = new Node(8);
    cout << "Original Linked List: ";
    printList(head);
    head=add1ToLL(head);
    cout << "Modified Linked List: ";
    printList(head);
    head=add1ToLL2(head);
    cout << "Modified Linked List: ";
    printList(head);
    return 0;
}
