// Segregate even and odd nodes

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
Node* oddEvenList(Node* head) {
    if (!head || !head->next || !head->next->next) return head; 
    
    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = even; 
    
    while (even && even->next) {
        odd->next = even->next; 
        odd = odd->next;
        even->next = odd->next; 
        even = even->next;
    }
    
    odd->next = evenHead; 
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
    head = oddEvenList(head);
    cout << "Reordered List: ";
    printList(head);
    return 0;
}
