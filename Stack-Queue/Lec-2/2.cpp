// Infix to prefix conversion 

#include<bits/stdc++.h>
using namespace std;




// Optimal O(3n) and O(2n)
int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void infixToPrefix(string s) {
    stack<char> st;
    string result;

    // Reverse the input string
    reverse(s.begin(), s.end());

    // Replace '(' with ')' and vice versa
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(')
            s[i] = ')';
        else if (s[i] == ')')
            s[i] = '(';
    }

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        // If the scanned character is an operand, add it to the output string
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;

        // If the scanned character is an ‘(‘, push it to the stack
        else if (c == '(')
            st.push('(');

        // If the scanned character is an ‘)’, pop and add to the output string until an ‘(‘ is 
        // encountered. An ‘(‘ is not popped out of the stack because a ‘(‘ is needed to match so pop out
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop();
        }

        // If an operator is scanned
        else {
            if(c == '^') { // Two power operators cannot be together
                while (!st.empty() && prec(c) <= prec(st.top())) {
                    result += st.top();
                    st.pop();
                }
            } else {
                while (!st.empty() && prec(c) < prec(st.top())) {
                    result += st.top();
                    st.pop();
                }
            }
            st.push(c);
        }
    }

    // Pop all the remaining elements from the stack
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    // Reverse the result to get the prefix expression
    reverse(result.begin(), result.end());
    cout << "Prefix expression: " << result << endl;
}




int main() {
    string exp = "(p+q)*(m-n)";
    cout << "Infix expression: " << exp << endl;
    infixToPrefix(exp);
    return 0;
}