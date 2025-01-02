// Remove outermost paranthesis

#include <bits/stdc++.h>
using namespace std;




// Optimal O(n) and O(n)
string removeOuterParentheses(string s) {
    string ans = "";
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            if (count > 0) ans += '(';
            count++;
        } else {
            count--;
            if (count > 0) ans += ')';
        }
    }
    return ans;
}




int main() {
    string input = "(()())(())";
    string result = removeOuterParentheses(input);
    cout << "Input: " << input << endl;
    cout << "Result after removing outer parentheses: " << result << endl;
    return 0;
}
