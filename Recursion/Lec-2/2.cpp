// Generate paranthesis

#include <bits/stdc++.h>
using namespace std;




// O(2^n) and O(n)
void helper(int n, vector<string>& ans, string s, int o, int c) {
    if (o == n && c == n) {
        ans.push_back(s);
        return;
    }
    
    if (o < n) {
        helper(n, ans, s + '(', o + 1, c); 
    }
    
    if (c < o) {
        helper(n, ans, s + ')', o, c + 1); 
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> ans;
    helper(n, ans, "", 0, 0); 
    return ans;
}




int main() {
    int n = 2; 
    vector<string> result = generateParenthesis(n);
    for (const string& str : result) {
        cout << str << endl;
    }

    return 0;
}

