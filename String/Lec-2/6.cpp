// Longest palindromic substring

#include <bits/stdc++.h>
using namespace std;




// Optimal O(n^3) and O(1)
bool check_palindrome(string &temp, int low,int high) {
    while (low <= high) {
        if (temp[low++] != temp[high--]) return false;
    }
    return true;
}

string longestPalindrome(string s) {
    int maxi = INT_MIN;
    int start=-1;
    int end=-1;
    for (int i = 0; i < s.length(); i++) {
        for (int j = i; j < s.length(); j++) {
            if (check_palindrome(s,i,j)) {
                if (j - i + 1 > maxi) {
                    start=i;
                    end=j;
                    maxi = j - i + 1;
                }
            }
        }
    }
    return s.substr(start,maxi);
}




int main() {
    string s="aabbaac";
    string result = longestPalindrome(s);
    cout << "The longest palindromic substring is: " << result << endl;
    return 0;
}


