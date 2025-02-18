// Add two linked list 

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




// Optimal O(max(m,n)) and O(max(m,n))
Node* addTwoNumbers(Node* l1, Node* l2) {
    Node* dummy = new Node(-1);
    Node* temp = dummy;
    int carry = 0;
    
    while ((l1 != nullptr || l2 != nullptr) || carry) {
        int sum = carry;
        
        if (l1 != nullptr) {
            sum += l1->data;
            l1 = l1->next;
        }
        
        if (l2 != nullptr) {
            sum += l2->data;
            l2 = l2->next;
        }
        
        carry = sum / 10;
        temp->next = new Node(sum % 10);
        temp = temp->next;
    }
    
    return dummy->next;
}




int main() {
    // Creating first linked list: 2 -> 4 -> 3
    Node* l1 = new Node(2);
    l1->next = new Node(4);
    l1->next->next = new Node(3);
    
    // Creating second linked list: 5 -> 6 -> 4
    Node* l2 = new Node(5);
    l2->next = new Node(6);
    l2->next->next = new Node(4);
    Node* result = addTwoNumbers(l1, l2);
    printList(result);
    return 0;
}
