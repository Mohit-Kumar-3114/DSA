// Reverse words in a string

#include <bits/stdc++.h>
using namespace std;




// Optimal O(2n) and O(2n)
void reverseString(string &str) { 
    int start = 0;
    int end = str.length() - 1;
    while (start < end) {
        swap(str[start++], str[end--]); 
    }
}

string reverseWords(string str) {
    string ans = ""; 
    string temp = ""; 
    for (int i = str.length() - 1; i >= 0; i--) {
        if (str[i] == ' ' && temp.empty()) {
            continue;  
        } else if (str[i] == ' ') {
            reverseString(temp); 
                ans += temp; 
                ans += ' ';
                temp = "";            
        } else {
            temp += str[i]; 
        }
    }

    // Add the last word if any exists in temp
    reverseString(temp);
    ans += temp;

    // Remove any trailing space from ans
    if (!ans.empty() && ans.back() == ' ') {
        ans.pop_back();
    }
    return ans;
}




int main() {
    string input = "hello world  ";
    string result = reverseWords(input);
    cout << "Input: \"" << input << "\"" << endl;
    cout << "Output: \"" << result << "\"" << endl;
    return 0;
}
