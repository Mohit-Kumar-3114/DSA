// Letter combinations of a phone number

#include<bits/stdc++.h>
using namespace std;




// Optimal (4^n * n) and O(4^n  * n)
void solve(string digit, string output, int index, vector<string>& ans, string mapping[]) {
    // Base case
    if (index >= digit.length()) {
        ans.push_back(output);
        return;
    }
    
    int number = digit[index] - '0';
    string value = mapping[number];
    
    for (int i = 0; i < value.length(); i++) {
        output.push_back(value[i]);
        solve(digit, output, index + 1, ans, mapping);
        output.pop_back();
    }
}




int main() {
    string digits = "23"; 
    vector<string> ans;
    if (digits.length() != 0) {
        string output;
        int index = 0;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digits, output, index, ans, mapping);
    }
    cout << "Letter combinations: ";
    for (const string& str : ans) {
        cout << str << " ";
    }
    cout << endl;
    return 0;
}
