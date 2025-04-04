// Implement stack using queue

#include <bits/stdc++.h>
using namespace std;




// Optimal O(size) for Push and O(1) for others and O(no. of elements in stack) 
class Stack {
    queue<int> q1;
public:
    void Push(int x) {
        int size = q1.size();
        q1.push(x);
        for (int i = 0; i < size; i++) {
            q1.push(q1.front());
            q1.pop();
        }  
    }

    int Pop() {
        if (q1.empty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        int popped = q1.front();
        q1.pop();
        return popped;
    }       

    int Top() {
        if (q1.empty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return q1.front();
    }   

    int Size() {
        return q1.size();
    }
};




int main() {
    Stack s;
    s.Push(1);
    s.Push(2);
    s.Push(3);
    cout << "Top: " << s.Top() << endl; 
    cout << "Pop: " << s.Pop() << endl; 
    cout << "Size: " << s.Size() << endl;
    cout << "Pop: " << s.Pop() << endl; 
    cout << "Pop: " << s.Pop() << endl; 
    cout << "Pop: " << s.Pop() << endl; 
    return 0;
}