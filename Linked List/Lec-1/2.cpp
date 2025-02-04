// Creating a linked list from array, searching in linked list and find length of linked list

#include <bits/stdc++.h>
using namespace std; 




class Node{
    public: // access modifier
    int data; // the data value
    Node* next; // the pointer to the next value
    public:
    // constructor
    Node (int data1, Node* next1){
        data=data1;  // Initialize data with the provided value
        next=next1;  // Initialize next with the provided
    }
    Node (int data1){
        data=data1;  // Initialize data with the provided value
        next=nullptr;  // Initialize next as null since it's the end of the list

    }
};




// Optimal O(n) and O(n)
Node* convertArr2LL(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}




// Optimal O(n) and O(1)
int lengthofLL(Node* head) {
    int cnt = 0;
    Node* temp = head;
    
    while (temp) {
        cout << temp->data << " -> "; // Printing elements
        temp = temp->next;
        cnt++;
    }
    cout << "NULL" << endl; 
    return cnt;
}




int main(){
    vector<int> arr={2,5,8,7};
    Node* head = convertArr2LL(arr);
    int length = lengthofLL(head);
    cout << "Length of Linked List: " << length << endl;
    return 0;
}