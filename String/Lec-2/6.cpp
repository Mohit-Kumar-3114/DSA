// Longest palindromic substring

#include <bits/stdc++.h>
using namespace std;




// Optimal O(n^3) and O(1)
bool check_palindrome(string &temp) {
    int low = 0;
    int high = temp.size() - 1;
    while (low <= high) {
        if (temp[low++] != temp[high--]) return false;
    }
    return true;
}

string longestPalindrome(string s) {
    int maxi = INT_MIN;
    string ans = "";
    for (int i = 0; i < s.length(); i++) {
        string temp = "";
        for (int j = i; j < s.length(); j++) {
            temp += s[j];
            if (check_palindrome(temp)) {
                if (j - i + 1 > maxi) {
                    ans = temp;
                    maxi = j - i + 1;
                }
            }
        }
    }
    return ans;
}




int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;
    string result = longestPalindrome(s);
    cout << "The longest palindromic substring is: " << result << endl;
    return 0;
}


