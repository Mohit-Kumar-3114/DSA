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




// Optimal O(1) and O(no. of elements in queue)
class Queue {
    Node* start;
    Node* end;
    int current_size;
public:
    Queue() {
        start = NULL;
        end = NULL;
        current_size = 0;
    }

    void Push(int x) {
        Node* newNode = new Node(x);
        if (current_size == 0) {
            start = newNode;
            end = newNode;
        } else {
            end->next = newNode;
            end = newNode;
        }
        current_size++;
    }

    int Pop() {
        if (start == NULL) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int popped = start->data;
        Node* temp = start;
        start = start->next;
        current_size--;
        delete temp;
        return popped;
    }

    int Front() {
        if (start == NULL) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return start->data;
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
