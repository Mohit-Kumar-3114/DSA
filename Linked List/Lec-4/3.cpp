// Remove duplicates from a sorted doubly linked list

#include <bits/stdc++.h>
using namespace std;




class Node {
    public:
    int data;
    Node* next;
    Node* prev;
    
    Node(int val) {
        data = val;
        next = prev = nullptr;
    }
};

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}




// Optimal O(n) and O(1)
Node* removeDuplicates(Node* head) {
    if (!head || !head->next) return head;
    Node* p = head;
    Node* n = head->next;
    while (n) {
        if (p->data == n->data) {
            Node* t = n;
            p->next = n->next;
            if (n->next) 
                n->next->prev = p;
            n = n->next;
            delete t;
        } else {
            p = n;
            n = n->next;
        }
    }
    return head;
}




int main() {
    Node* head = new Node(1);
    head->next = new Node(1);
    head->next->prev = head;
    head->next->next = new Node(2);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(3);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(3);
    head->next->next->next->next->prev = head->next->next->next;
    cout << "Original list: ";
    printList(head);
    head = removeDuplicates(head);
    cout << "List after removing duplicates: ";
    printList(head);
    return 0;
}
