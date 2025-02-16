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
Node* middle(Node* head) {
    if (!head || !head->next) return head;
    Node* slow = head;
    Node* fast = head->next->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* deleteMiddle(Node* head) {
    if (!head || !head->next) return nullptr;
        Node* prevMid = middle(head);
        Node* toDelete = prevMid->next;
        prevMid->next = prevMid->next->next;
        delete toDelete;
        return head;
}




int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    cout << "Original List: ";
    printList(head);
    head=deleteMiddle(head);
    cout<<"Modified List: ";
    printList(head);
    return 0;
}