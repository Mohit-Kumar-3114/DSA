// Reverse nodes in k groups in a linked list 

#include <bits/stdc++.h>
using namespace std; 




class Node {
public:
    int data;
    Node* next;
    Node(int data1) {
        data = data1;
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




// Optimal O(2n) and O(1)
Node* reverseLL(Node* head){
    Node* p=0;
    Node* c=head;
    Node* n;
    while(c){
        n=c->next;
        c->next=p;
        p=c;
        c=n;
    }
  return p;
}

Node* getKthNode(Node* temp, int k){
    k -= 1; 
    while(temp != NULL && k > 0){
        k--; 
        temp = temp -> next; 
    }
    return temp; 
}

Node* kReverse(Node* head, int k){
    if (!head || k == 1 || !head->next) return head; 
    Node* temp = head; 
    Node* prevLast = NULL; 
    while(temp != NULL){
        Node* kThNode = getKthNode(temp, k); 
        if(kThNode == NULL){
            if(prevLast){
                prevLast -> next = temp; 
            }
            break; 
        }
        Node* nextNode = kThNode -> next; 
        kThNode -> next = NULL; 
        kThNode=reverseLL(temp); 
        if(temp == head){
            head = kThNode;
        }else{
            prevLast -> next = kThNode; 
        }
        prevLast = temp; 
        temp = nextNode; 
    }
    return head; 
}




int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    cout<<"Original linked list : ";
    printList(head);
    head=kReverse(head,3);
    cout<<"Modified linked list : ";
    printList(head);
    return 0;
}
