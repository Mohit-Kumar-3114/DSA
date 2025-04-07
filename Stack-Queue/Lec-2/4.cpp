// Prefix to infix conversion

#include <bits/stdc++.h>
using namespace std;




// Optimal O(2n) and O(n)
void prefixToInfix(string s) {
    stack<string> st;

    // Traverse the prefix expression from right to left
    for (int i = s.length() - 1; i >= 0; i--) {
        char c = s[i];

        // If the scanned character is an operand, push it to the stack
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            st.push(string(1, c));
        } else {
            // Pop two operands from the stack
            string op1 = st.top(); 
            st.pop();
            string op2 = st.top(); 
            st.pop();
            string temp = "(" + op1 + c + op2 + ")"; // Takes O(n) time in total
            st.push(temp);
        }
    }

    // The final result is the only element left in the stack
    cout << "Infix: " << st.top() << endl;
}




int main() {
    string prefix = "*+pq-mn"; 
    prefixToInfix(prefix);
    return 0;
}