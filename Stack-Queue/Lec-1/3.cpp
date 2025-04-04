// Implement stack using linked list

#include<bits/stdc++.h>
using namespace std;




class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};




// Optimal O(1) and O(no. of elements in stack)
class Stack {
    Node* head;
    int current_size;
public:
    Stack() {
        head = NULL;
        current_size = 0;
    }

    void Push(int x) {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
        current_size++;
    }

    int Pop() {
        if (head == NULL) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        int popped = head->data;
        Node* temp = head;
        head = head->next;
        current_size--;
        delete temp;
        return popped;
    }

    int Top() {
        if (head == NULL) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return head->data;
    }

    int Size() {
        return current_size;
    }
};




int main() {
    Stack s;
    s.Push(1);
    s.Push(2);
    s.Push(3);
    cout << "Top element: " << s.Top() << endl; 
    cout << "Stack size: " << s.Size() << endl; 
    cout << "Popped element: " << s.Pop() << endl; 
    cout << "Stack size: " << s.Size() << endl; 
    cout << "Top element: " << s.Top() << endl; 
    return 0;
}