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
    top++;
    arr[top] = x;
    }

    int Pop() {
    int x = arr[top];
    top--;
    return x;
    }

    int Top() {
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
  cout << "Top of stack is before deleting any element " << s.Top() << endl;
  cout << "Size of stack before deleting any element " << s.Size() << endl;
  cout << "The element deleted is " << s.Pop() << endl;
  cout << "Size of stack after deleting an element " << s.Size() << endl;
  cout << "Top of stack after deleting an element " << s.Top() << endl;
  return 0;
}