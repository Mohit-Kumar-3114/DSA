// Delete the middle node of a linked list

#include <bits/stdc++.h>
using namespace std;




class Node {
    public:
        int data;      
        Node* next;
    
        Node(int data1, Node* next1) {
            data = data1;
            next = next1;
        }
    
        Node(int data1) {
            data = data1;
            next = nullptr;
        }
};

// Function to print the linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}




// Optimal O(n) and O(1)
Node* middle2(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* deleteMiddle(Node* head) {
    Node* mid = middle2(head);
    if (head == mid) return nullptr;
    
    Node* temp = head;
    while (temp->next != mid) { 
        temp = temp->next;
    }
    
    temp->next = mid->next;
    delete mid;
    return head;
}




int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    cout << "Original List: ";
    printList(head);
    head=deleteMiddle(head);
    cout<<"Modified List: ";
    printList(head);
    return 0;
}