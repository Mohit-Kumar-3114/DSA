// Postfix to prefix conversion

#include <bits/stdc++.h>
using namespace std;    




// Optimal O(2n) and O(n)
void postfixToPrefix(string s) {
    stack<string> st;

    for (char c : s) {
        // If the scanned character is an operand, push it to the stack
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            st.push(string(1, c));
        } else {
            // Pop two operands from the stack
            string op1 = st.top(); 
            st.pop();
            string op2 = st.top(); 
            st.pop();
            string temp = c + op2 + op1; // Takes O(n) time in total
            st.push(temp);
        }
    }

    // The final result is the only element left in the stack
    cout << "Prefix: " << st.top() << endl;
}




int main() {
    string postfix = "ab-de+f*/"; 
    postfixToPrefix(postfix);
    return 0;
}