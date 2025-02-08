// Deleting node in a doubly linked list

#include <bits/stdc++.h>
using namespace std; 




class Node {
public:
    int data;
    Node* next;
    Node* back;

    // Constructors
    Node(int data1, Node* next1 , Node* back1) {
        data = data1;
        next = next1;
        back=back1;
    }
    Node(int data1) {
        data = data1;
        next = nullptr;
        back= nullptr;
    }
};

// Function to convert an array to a linked list
Node* convertArr2LL(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        temp->back=mover;
        mover->next = temp;
        mover = temp;
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
void deleteFromStart(Node* &head) {
    if (head == nullptr) return; 
    else if(head->next==nullptr){
        delete head;
        head=nullptr;
    }
    else{
    Node* temp = head;
    head = head->next;
    head->back=nullptr;
    delete temp; 
    }
}




// Optimal O(n) and O(1)
void deleteFromEnd(Node* &head){
    if (head == nullptr) return; 
    else if(head->next==nullptr){
        delete head;
        head=nullptr;
        return;
    }
    else{
     Node* temp=head;
     while(temp->next->next){
        temp=temp->next;
     }
     delete temp->next;
     temp->next=nullptr;
    }
}




// Optimal O(n) and O(1)
void deleteFromKthPosition(Node* &head, int k){
    if (head == nullptr) return;
    int length = lengthofLL(head);
    if(k==1) deleteFromStart(head);
    else if(k==length) deleteFromEnd(head);
    else if(k>length) return;
    else{
     Node* temp=head;
     for(int i=1;i<k-1;i++) temp=temp->next;
     Node* t=temp->next;
     temp->next=temp->next->next;
     if(temp->next) temp->next->back=temp;
     delete t;
    }
}




// Optimal O(n) and O(1)
void deleteValue(Node* &head, int element){
    if(head==nullptr) return;
    if(head->data==element){
    Node* x=head;
    head=head->next;
    head->back=nullptr;
    delete x;
    return;
    }
    Node* temp=head;
    while(temp->next){
    if(temp->next->data==element){
    Node* t=temp->next;
    temp->next=temp->next->next;
    if(temp->next) temp->next->back=temp;
    delete t;
    return;
    }
    temp=temp->next;
    }
}




int main() {
    vector<int> arr = {2, 5, 8, 7, 9, 11, 14, 16};
    Node* head = convertArr2LL(arr);

    cout << "Original Linked List: ";
    printLinkedList(head);

    deleteFromStart(head);
    cout << "After Deleting First Node: ";
    printLinkedList(head);

    deleteFromEnd(head);
    cout<<"After Deleting Last Node: ";
    printLinkedList(head);

    deleteFromKthPosition(head,4);
    cout<<"After Deleting Kth Node: ";
    printLinkedList(head);

    deleteValue(head,7);
    cout<<"After Deleting Element: ";
    printLinkedList(head);

    return 0;
}
