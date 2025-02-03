// Count number of substrings

#include <bits/stdc++.h>
using namespace std;




// Optimal O(n^2) and O(1)
int strCount(string s,int k) {
    int sum = 0;
        for (int i = 0; i < s.length(); i++) {
            unordered_map<char, int> freqMap;
            for (int j = i; j < s.length(); j++) {
                freqMap[s[j]]++;
                int temp = 0;
                for (auto it : freqMap) {
                    if (it.second > 0) temp++;
                }
                if (temp == k) sum++;
            }
        }
        return sum;
}




int main() {
    string s="abaaca";
    int k=3;
    int result = strCount(s,k);
    cout << "count : " << result << endl;
    return 0;
}
