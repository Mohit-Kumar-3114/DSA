// Creating node for linked list

#include <bits/stdc++.h>
using namespace std; 




class Node{
    public: // access modifier
    int data; // the data value
    Node* next; // the pointer to the next value
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




int main(){
    vector<int> arr={2,5,8,7};
    Node* z= new Node(arr[1]);
    Node* y= new Node(arr[0],z);
    cout << z << "\n"; // Prints the memory address of node z
    cout << y << '\n'; // Prints the memory address of node y
    cout << y->data << '\n'; // Prints the data stored in node y (2)
    cout << y->next << '\n'; // Prints the memory address of the next node (which is z) 
    return 0;
}
