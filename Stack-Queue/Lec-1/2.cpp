// Implement Queue using array

#include<bits/stdc++.h>
using namespace std;




// Optimal O(1) and O(size)
class Queue {
    int size;
    int *arr;
    int start;
    int end;
    int current_size;

public:
    Queue() {
        size = 1000; // given in the interview
        arr = new int[size];
        start = -1;
        end = -1;
        current_size = 0;
    }

    void Push(int x) {
        if (current_size == size) {
            cout << "Queue is full" << endl;
            return;
        }
        if (start == -1) {
            start = 0;
        }
        end = (end + 1) % size; // circular queue
        arr[end] = x;
        current_size++;
    }

    int Pop() {
        if (current_size == 0) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int popped = arr[start];
        if (current_size == 1) {
            start = -1;
            end = -1;
        } else {
            start = (start + 1) % size; // circular queue
        }
        current_size--;
        return popped;
    }

    int Front() {
        if (current_size == 0) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[start];        
    }

    int Size() {
        return current_size;
    }
};




int main() {
    Queue q;
    q.Push(6);
    q.Push(3);
    q.Push(7);
    cout << "Front of queue is before deleting any element " << q.Front() << endl;
    cout << "Size of queue before deleting any element " << q.Size() << endl;
    cout << "The element deleted is " << q.Pop() << endl;
    cout << "Size of queue after deleting an element " << q.Size() << endl;
    cout << "Front of queue after deleting an element " << q.Front() << endl;
    return 0;
}