// Sum of beauty of all substrings

#include <bits/stdc++.h>
using namespace std;




// Optimal O(n^2) and O(1)
int beautySum(string s) {
    int sum = 0;
    for (int i = 0; i < s.length(); i++) {
        unordered_map<char, int> freqMap;
        for (int j = i; j < s.length(); j++) {
            freqMap[s[j]]++;
            int maxi = 0, mini = INT_MAX;
            for (auto it : freqMap) {
                mini = min(mini, it.second);
                maxi = max(maxi, it.second);
            }
            sum += (maxi - mini);
        }
    }
    return sum;
}




int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    int result = beautySum(s);
    cout << "Beauty sum: " << result << endl;
    return 0;
}
