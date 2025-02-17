// Find intersection of two linked list 

#include <bits/stdc++.h>
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




// Brute O(m+n) and O(m+n)
Node* getIntersectionNodeHashing(Node* head1, Node* head2) {
    unordered_map<Node*, int> mpp;
    while (head1) {
        mpp[head1]++;
        head1 = head1->next;
    }
    while (head2) {
        if (mpp.find(head2) != mpp.end()) return head2;
        head2 = head2->next;
    }
    return NULL;
}




// Better O(m + n + (m - n) + n) and O(1)
Node* getIntersectionNodeDifference(Node* head1, Node* head2) {
    int n = 0, m = 0;
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    while (ptr1) { 
        n++; 
        ptr1 = ptr1->next; 
    }
    while (ptr2) {
         m++; 
         ptr2 = ptr2->next;
    }
    int diff = abs(n - m);
    if (n > m) while (diff--) head1 = head1->next;
    else while (diff--) head2 = head2->next;
    while (head1 && head2) {
        if (head1 == head2) return head1;
        head1 = head1->next;
        head2 = head2->next;
    }
    return NULL;
}




// Optimal O(m+n) and O(1)
Node* getIntersectionNode(Node* head1, Node* head2) {
    Node* d1 = head1;
    Node* d2 = head2;
    while (d1 != d2) {
        d1 = d1 == NULL ? head2 : d1->next;
        d2 = d2 == NULL ? head1 : d2->next;
    }
    return d1;
}




int main() {
    // Creating linked list 1: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    
    // Creating linked list 2: 9 -> 10 -> NULL
    Node* head2 = new Node(9);
    head2->next = new Node(10);
    
    // Creating the intersection at node 4
    Node* common = new Node(4);
    common->next = new Node(5);
    
    head1->next->next->next = common;
    head2->next->next = common;

    cout << "List 1: ";
    printList(head1);
    cout << "List 2: ";
    printList(head2);

    Node* intersectionHash = getIntersectionNodeHashing(head1, head2);
    if (intersectionHash)
        cout << "Intersection (Hashing) at node with value: " << intersectionHash->data << endl;
    else
        cout << "No intersection found (Hashing)." << endl;

    Node* intersectionDiff = getIntersectionNodeDifference(head1, head2);
    if (intersectionDiff)
        cout << "Intersection (Difference Method) at node with value: " << intersectionDiff->data << endl;
    else
        cout << "No intersection found (Difference Method)." << endl;

    Node* intersectionTwoPointer = getIntersectionNode(head1, head2);
    if (intersectionTwoPointer)
        cout << "Intersection (Two Pointer) at node with value: " << intersectionTwoPointer->data << endl;
    else
        cout << "No intersection found (Two Pointer)." << endl;
    
    return 0;
}
