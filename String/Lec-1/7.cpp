// Check if two strings are anagram of each other

#include <bits/stdc++.h>
using namespace std;




// Brute O(n + n log n) and O(log n) 
bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}




// Optimal O(n) and O(1)
bool isAnagram2(string s, string t) {
    if (s.length() != t.length()) return false;
    int arr[26] = {0};
    for (int i = 0; i < s.length(); i++) {
        arr[s[i] - 'a']++;
        arr[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
        if (arr[i] != 0) return false;
    }
    return true;
}




int main() {
    string s = "anagram";
    string t = "angaram";
    if (isAnagram(s, t)) {
        cout << "Yes, they are anagrams." << endl;
    } else {
        cout << "No, they are not anagrams." << endl;
    }
     if (isAnagram2(s, t)) {
        cout << "Yes, they are anagrams." << endl;
    } else {
        cout << "No, they are not anagrams." << endl;
    }
    return 0;
}
