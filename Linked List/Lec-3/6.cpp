// Check if a linked list is palindrome or not

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
    



// Optimal O(n) and O(1)
Node* middle(Node* head) {
    Node* slow = head;
    Node* fast = head->next->next; // to reach one node before middle
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

bool isPalindrome(Node* head) {
    if (!head || !head->next) return true;

    Node* mid = middle(head);
    Node* c = mid->next;
    mid->next = NULL;

    // Reverse second half
    Node* p = NULL;
    Node* n;
    while (c) {
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }

    while (head && p) {
        if (head->data != p->data) return false;
        head = head->next;
        p = p->next;
    }
    return true;
}




int main() {
    // Manually creating a linked list: 1 -> 2 -> 2 -> 1
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);

    if (isPalindrome(head)) {
        cout << "The linked list is a palindrome.\n";
    } else {
        cout << "The linked list is not a palindrome.\n";
    }
    return 0;
}
