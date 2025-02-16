// Sort a linked list of 0's 1's and 2's by changing links

#include <iostream>
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

// Function to print the linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}




// Optimal O(n) and O(1)
Node* segregate(Node* head) {
    if (!head || !head->next) return head; 
    
    Node* zero = new Node(-1);
    Node* one = new Node(-1);
    Node* two = new Node(-1);
    Node* zero_x = zero;
    Node* one_x = one;
    Node* two_x = two;
    Node* temp = head;
    while (temp) {
        if (temp->data == 0) {
            zero_x->next = temp;
            zero_x = zero_x->next;
        } else if (temp->data == 1) {
            one_x->next = temp;
            one_x = one_x->next;
        } else {
            two_x->next = temp;
            two_x = two_x->next;
        }
        temp = temp->next;
    }

    // Linking the lists together
    zero_x->next = one->next ? one->next : two->next;
    one_x->next = two->next;
    two_x->next = nullptr;
    Node* newHead = zero->next; 
    return newHead;
}




int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(0);
    head->next->next->next->next->next->next = new Node(1);
    cout << "Original List: ";
    printList(head);
    head = segregate(head);
    cout << "Sorted List: ";
    printList(head);
    return 0;
}
