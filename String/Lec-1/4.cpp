// Longest common prefix

#include <bits/stdc++.h>
using namespace std;




// Optimal O(n * m) and O(n)
string longestCommonPrefix(vector<string>& strs) { 
    string ans = "";
    for (int i = 0; i < strs[0].size(); i++) {  
        for (auto s : strs) {  
            if (s[i] != strs[0][i]) return ans;  
        }
        ans += strs[0][i];  
    }
    return ans;
}




int main() {
    vector<string> strs = {"flower", "flow", "floght"};
    string result = longestCommonPrefix(strs);
    cout << "Longest Common Prefix: " << result << endl;
    return 0;
}
