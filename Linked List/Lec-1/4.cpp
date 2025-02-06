// Inserting node in a linked list

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

// Function to print linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}




// Optimal O(1) and O(1)
void insertAtStart(Node* &head, int element) {
   Node* temp=new Node(element,head);
   head=temp;
}




// Optimal O(n) and O(1)
void insertAtEnd(Node* &head, int element) {
   if (head == nullptr) {
    head = new Node(element, nullptr);
    return;
  }
  Node* temp=head;
  while(temp->next){
  temp=temp->next;
  }
  Node* n= new Node (element,nullptr);
  temp->next=n;
}




// Optimal O(n) and O(1)
void insertAtKthPosition(Node* &head,int element,int k){
    if(head==nullptr){
    head = new Node(element, nullptr);
    return;  
    }
    int length=lengthofLL(head);
    if(k==1) insertAtStart(head,element);
    else if(k==length+1) insertAtEnd(head,element);
    else if(k>length+1) return;
    else {
    Node* temp=head;
    for(int i=1;i<k-1;i++){
    temp=temp->next;
    }
    Node* n=new Node(element,nullptr);
    n->next=temp->next;
    temp->next=n;
    }
}




// Optimal O(n) and O(1)
void insertValue(Node* &head, int element,int x){
    if(head==nullptr) return;
    if(head->data==element){
    Node* n=new Node(x,head);
    head=n;
    return;
    }
    Node* temp=head;
    while(temp->next){
    if(temp->next->data==element){
    Node* n=new Node(x,nullptr);
    n->next=temp->next;
    temp->next=n;
    return;
    }
    temp=temp->next;
    }
}




int main() {
    vector<int> arr = {2, 5, 7, 8, 9, 11, 14, 16};
    Node* head = convertArr2LL(arr);
    cout << "Original Linked List: ";
    printLinkedList(head);
    
    insertAtStart(head,1);
    cout << "After Inserting First Node: ";
    printLinkedList(head);

    insertAtEnd(head,20);
    cout << "After Inserting Last Node: ";
    printLinkedList(head);

    insertAtKthPosition(head,4,3);
    cout << "After Inserting Kth Node: ";
    printLinkedList(head);

    insertValue(head,16,15);
    cout << "After Inserting Element: ";
    printLinkedList(head);

    return 0;
}
