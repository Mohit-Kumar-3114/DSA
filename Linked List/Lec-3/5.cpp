// Length of loop in linked list 

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




// Brute O(2n) and O(n)
Node* firstNode(Node* head){
    unordered_map<Node*, int> mpp;
    Node* temp=head;
    while(temp){
    if(mpp.find(temp)!=mpp.end()) return temp;
    mpp[temp]=1;
    temp=temp->next;
    }  
    return nullptr;
}

int countNodesinLoop(Node *head) {
    Node* temp=firstNode(head);
    if(temp==NULL) return 0;
    int count=1;
    Node* temp2=temp->next;
    while(temp!=temp2){
        count++;
        temp2=temp2->next;
    }
    return count;
}




// Optimal O(2n) and O(1)
Node* firstNode2(Node* head) {
    // Floyd’s Cycle Detection Algorithm
    Node* slow = head;  
    Node* fast = head;  

    // Phase 1: Detect the loop
    while (fast != NULL && fast->next != NULL) {
        
        // Move slow one step
        slow = slow->next;        
        
        // Move fast two steps
        fast = fast->next->next;  

        // If slow and fast meet,
        // a loop is detected
        if (slow == fast) {
            
             // Reset the slow pointer
             // to the head of the list
            slow = head; 

            // Phase 2: Find the first node of the loop
            while (slow != fast) {
                
                // Move slow and fast one step
                // at a time
                slow = slow->next;  
                fast = fast->next;  

                // When slow and fast meet again,
                // it's the first node of the loop
            }
            
            // Return the first node of the loop
            return slow;  
        }
    }
    
     // If no loop is found, return NULL
    return NULL; 
}

int countNodesinLoop2(Node *head) {
    Node* temp=firstNode2(head);
    if(temp==NULL) return 0;
    int count=1;
    Node* temp2=temp->next;
    while(temp!=temp2){
        count++;
        temp2=temp2->next;
    }
    return count;
}




int main() {
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    node1-> next = node2;
    Node* node3 = new Node(3);
    node2-> next = node3;
    Node* node4 = new Node(4);
    node3->next = node4;
    Node* node5 = new Node(5);
    node4-> next = node5;

    // Make a loop from node5 to node2
    node5->next = node2;

    // Set the head of the linked list
    Node* head = node1;
    int length = countNodesinLoop(head);
    int length2=countNodesinLoop2(head);
    cout<<length<<"  "<<length2;
    return 0;
}
                                
                            