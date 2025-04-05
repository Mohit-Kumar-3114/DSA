// Implement min stack

#include <bits/stdc++.h>
using namespace std;




// Brute O(1) and O(2n) 
class MinStack {
    stack<pair<int, int>> st;

public:
    MinStack() {}

    void Push(int val) {
        if (st.empty()) {
            st.push({val, val});
        } else {
            int currentMin = min(val, st.top().second);
            st.push({val, currentMin});
        }
    }

    void Pop() {
        if (!st.empty()) {
            st.pop();
        }
    }

    int Top() {
        if (st.empty()) return -1;
        return st.top().first;
    }

    int getMin() {
        if (st.empty()) return -1;
        return st.top().second;
    }
};




// Optimal O(1) and O(n) 
class MinStack2 {
    stack<long long> st; 
    long long mini; 
public:
    MinStack2() {
        mini = LLONG_MAX; 
    }
    
    void Push(int val) {
        long long value = val;
        if(st.empty()) {
            st.push(value); 
            mini = value; 
        } else {
            if(value < mini) {
                st.push(2*value - mini); 
                mini = value; 
            } else {
                st.push(value); 
            }
        }
    }
    
    void Pop() {
        if(st.empty()) return; 
        long long topVal = st.top();
        if(topVal < mini) {
            mini = 2*mini - topVal; 
        }
        st.pop();     
    }
    
    int Top() {
        if(st.empty()) return -1; 
        long long topVal = st.top();
        if(topVal < mini) return mini; 
        return topVal;   
    }
    
    int getMin() {
        return mini;  
    }
};




int main() {
    cout << "Testing MinStack:" << endl;
    MinStack obj1;
    obj1.Push(3);
    obj1.Push(5);
    cout << "Minimum: " << obj1.getMin() << endl; 
    obj1.Push(2);    
    obj1.Push(1);
    cout << "Minimum: " << obj1.getMin() << endl;
    obj1.Pop();
    cout << "Top: " << obj1.Top() << endl;

    cout << "\nTesting MinStack2:" << endl;
    MinStack2 obj2;
    obj2.Push(3);
    obj2.Push(5);
    cout << "Minimum: " << obj2.getMin() << endl; 
    obj2.Push(2);    
    obj2.Push(1);
    cout << "Minimum: " << obj2.getMin() << endl;
    obj2.Pop();
    cout << "Top: " << obj2.Top() << endl;

    return 0; 
}