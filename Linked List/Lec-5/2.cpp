// Rotate a linked list 

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

// Function to print a linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}




// Optimal O(n + n - k) and O(1)
Node* rotateRight(Node* head, int k) {
    if (!head || !head->next) return head;
    int n = 1;
    Node* temp = head;
    while (temp->next) {
        n++;
        temp = temp->next;
    }
    k = k % n;
    if (k == 0) return head;

    // Connect the last node to the head to form a cycle
    temp->next = head;

    // Find the new tail (n-k-1)th node
    Node* newTail = head;
    int toStop = n - k - 1;
    while (toStop--) {
        newTail = newTail->next;
    }

    // Break the cycle and set the new head
    Node* newHead = newTail->next;
    newTail->next = nullptr;

    return newHead;
}




int main() {
    // Creating linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int k = 2; // Rotate by k places
    head = rotateRight(head, k);

    // Printing rotated list
    printList(head);

    return 0;
}
