// Delete all occurences of a key in doubly linked list 

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
void deleteAllOccurOfX(Node*& head, int x) {
    Node* cur = head;
    while (cur) {
        if (cur->data == x) {
            Node* temp = cur;
            if (cur == head) {
                head = head->next;
                if (head) head->prev = nullptr;
            } else {
                if (cur->prev) cur->prev->next = cur->next;
                if (cur->next) cur->next->prev = cur->prev;
            }
            cur = cur->next;
            delete temp;
        } else {
            cur = cur->next;
        }
    }
}




int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(2);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->prev = head->next->next->next;
    
    cout << "Original List: ";
    printList(head);
    
    int x = 2;
    deleteAllOccurOfX(head, x);
    
    cout << "List after deleting all occurrences of " << x << ": ";
    printList(head);
    
    return 0;
}
