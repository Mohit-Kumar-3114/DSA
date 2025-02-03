// Implement atoi

#include <bits/stdc++.h>
using namespace std;




// Optimal O(n) and O(1)
int myAtoi(string s) {
    int i = 0;
    long ans = 0;
    bool flag = true;

    // Skip leading spaces
    while (i < s.length() && s[i] == ' ') i++;

    // Ensure index is within bounds before checking signs
    if (s[i] == '-') {
        flag = false;
        i++;
    } else if (s[i] == '+') {
        i++;
    }

    // Process digits and handle overflow
    while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
        ans = ans * 10 + (s[i] - '0');
        if (ans > INT_MAX) {
            return flag ? INT_MAX : INT_MIN;
        }
        i++;
    }
    return flag ? ans : -ans;
}




int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);
    int result = myAtoi(s);
    cout << "Converted integer: " << result << endl;
    return 0;
}