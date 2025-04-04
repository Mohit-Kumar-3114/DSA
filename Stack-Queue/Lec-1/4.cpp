// Implement queue using linked list

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




// Optimal O(1) and O(no of elements in queue)
class Queue {
    Node* front;
    Node* rear;
    int current_size;
public:
    Queue() {
        front = NULL;
        rear = NULL;
        current_size = 0;
    }

    void Push(int x) {
        Node* newNode = new Node(x);
        if (current_size == 0) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        current_size++;
    }

    int Pop() {
        if (front == NULL) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int popped = front->data;
        Node* temp = front;
        front = front->next;
        current_size--;
        delete temp;
        return popped;
    }

    int Front() {
        if (front == NULL) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }

    int Size() {
        return current_size;
    }
};




int main() {
    Queue q;
    q.Push(1);
    q.Push(2);
    q.Push(3);
    cout << "Front: " << q.Front() << endl; 
    cout << "Size: " << q.Size() << endl; 
    cout << "Pop: " << q.Pop() << endl; 
    cout << "Front: " << q.Front() << endl; 
    cout << "Size: " << q.Size() << endl; 
    return 0;
}