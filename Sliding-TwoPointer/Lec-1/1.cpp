// Longest substring without repeating characters

#include <bits/stdc++.h>
using namespace std;




// Brute O(n^2) and O(1)
int lengthOfLongestSubstring(string s) {
    if (s.length() == 0) return 0;
    if (s.length() == 1) return 1;
    int length = 0;
    for (int i = 0; i < s.length() - 1; i++) {
        int count = 1;
        int arr[256] = {0};
        
        for (int j = i + 1; j < s.length(); j++) {
            if (s[i] != s[j]) {
                if (arr[s[j]] > 0) break;
                else {
                    arr[s[j]]++;
                    count++;
                }
            } else break;
        }  
        length = max(count, length);
    }
    return length;
}




// Optimal O(n) and O(1)
int lengthOfLongestSubstring2(string s) {
    if (s.length() == 0) return 0;
    if (s.length() == 1) return 1;
    vector < int > mpp(256, -1);
      int left = 0, right = 0;
      int n = s.size();
      int len = 0;
      while (right < n) {
        if (mpp[s[right]] != -1){
          left = max(mpp[s[right]] + 1, left);
        }
        mpp[s[right]] = right;

        len = max(len, right - left + 1);
        right++;
      }
      return len;
}




int main() {
    string s="abcbcad";
    int result = lengthOfLongestSubstring(s);
    cout << "Length of the longest substring without repeating characters: " << result << endl;
    int result2 = lengthOfLongestSubstring2(s);
    cout << "Length of the longest substring without repeating characters: " << result << endl;
    return 0;
}