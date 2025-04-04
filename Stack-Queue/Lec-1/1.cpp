// Implement stack using array

#include<bits/stdc++.h>
using namespace std;




// Optimal O(1) and O(size)
class Stack {
  int size;
  int * arr;
  int top;
  public:
    Stack() {
      top = -1;
      size = 1000; // given in the interview
      arr = new int[size];
    }

    void Push(int x) {
      if (top == size - 1) {
        cout << "Stack Overflow! Cannot push " << x << endl;
        return;
      }
      top++;
      arr[top] = x;
    }

    int Pop() {
      if (top == -1) {
        cout << "Stack Underflow! Cannot pop from an empty stack." << endl;
        return -1; 
      }
      int x = arr[top];
      top--;
      return x;
    }

    int Top() {
      if (top == -1) {
        cout << "Stack is empty! No top element." << endl;
        return -1;
      }
      return arr[top];
    }

    int Size() {
      return top + 1;
    }
};




int main() {
  Stack s;
  s.Push(6);
  s.Push(3);
  s.Push(7);
  cout << "Top of stack is before deleting any element: " << s.Top() << endl;
  cout << "Size of stack before deleting any element: " << s.Size() << endl;
  cout << "The element deleted is: " << s.Pop() << endl;
  cout << "Size of stack after deleting an element: " << s.Size() << endl;
  cout << "Top of stack after deleting an element: " << s.Top() << endl;
  return 0;
}