// Delete kth node from end of a linked list

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
Node* removekthFromEnd(Node* head, int k) {
    Node* temp = head;
    int count = 0;
    while (temp) {
        count++;
        temp = temp->next;
    }
    if (count == k) {
        Node* t = head;
        head = head->next;
        delete t;
    }  
    else if (k == 1) {
        Node* t = head;
        while (t->next->next) {
            t = t->next;
        }
        delete t->next;
        t->next = nullptr;
    }
    else { 
        int x = count - k + 1; // kth from end is xth from start
        Node* nod = head;
        for (int i = 1; i < x - 1; i++) nod = nod->next;
        Node* t = nod->next;
        nod->next = nod->next->next;
        delete t;
    }
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
    head=removekthFromEnd(head,5);
    cout<<"Modified List: ";
    printList(head);
    return 0;
}
