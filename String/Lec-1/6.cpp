// Check whether one string is a rotation of other 

#include <bits/stdc++.h>
using namespace std;




// Brute O(3n^2) and O(n)
bool isSame(string &temp, string &goal) {
    for (int i = 0; i < temp.length(); i++) {
        if (temp[i] != goal[i]) {
            return false;
        }
    }
    return true;
}

void reverseSubstring(string &temp, int start, int end) {
    while (start <= end) {
        swap(temp[start++], temp[end--]);
    }
}

void reverseStr(string &temp, int i) {
    reverseSubstring(temp, 0, i - 1);
    reverseSubstring(temp, i, temp.length() - 1);
    reverseSubstring(temp, 0, temp.length() - 1);
}

bool rotateString(string s, string goal) {
    if (s.length() != goal.length()) {
        return false;
    }

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == goal[0]) {
            string temp = s;
            reverseStr(temp, i);
            if (isSame(temp, goal)) {
                return true;
            }
        }
    }
    return false;
}




// Optimal O(2n) and O(2n)
bool rotateString2(string s, string goal) {
    if (s.length() != goal.length()) {
        return false;
    }
    string doubled = s + s;
    return doubled.find(goal) != -1; 
}




int main() {
    string s = "abcde";
    string goal = "edcab";

    if (rotateString(s, goal)) {
        cout << "The string can be rotated to match the goal." << endl;
    } else {
        cout << "The string cannot be rotated to match the goal." << endl;
    }
    
    if (rotateString2(s, goal)) {
        cout << "The string can be rotated to match the goal." << endl;
    } else {
        cout << "The string cannot be rotated to match the goal." << endl;
    }
    return 0;
}