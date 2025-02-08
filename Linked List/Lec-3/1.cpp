// Find middle of a linked list

#include <bits/stdc++.h>
using namespace std; 




class Node {
public:
    int data;
    Node* next;

    // Constructors
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Function to convert an array to a linked list
Node* convertArr2LL(vector<int>& arr) {
    if (arr.empty()) return nullptr; 
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size(); i++) {
        mover->next = new Node(arr[i]);
        mover = mover->next;
    }
    return head;
}

// Function to calculate length of linked list
int lengthofLL(Node* head) {
    int cnt = 0;
    Node* temp = head;
    while (temp) {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}




// Brute O(2n) and O(1)
Node* middle1(Node* head){
   int length=lengthofLL(head);
   int count=length/2;
   Node* mid=head;
   while(count){
   mid=mid->next;
   count--;
   }
   return mid;
}




// Optimal O(n/2) and O(1)
Node* middle2(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}




int main() {
    vector<int> arr = {2, 5, 8, 7, 9, 11, 14, 16};
    Node* head = convertArr2LL(arr);
    Node* mid=middle1(head);
    cout<<"Brute force : "<< mid->data<<endl;
    Node* mid2=middle2(head);
    cout<<"Brute force : "<< mid2->data<<endl;
    return 0;
}