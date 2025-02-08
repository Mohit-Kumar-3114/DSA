// Palindrome partitioning

#include <bits/stdc++.h>
using namespace std;




// Optimal O(2^n * k * n/2) and O(k * x) where k=average length and x=no. of palindrome
bool isPalindrome(string &s, int start, int end) {
    while (start <= end) {
        if (s[start++] != s[end--])
            return false;
    }
    return true;
}

void partitionHelper(int index, string &s, vector<string> &path, vector<vector<string>> &res) {
    if (index == s.size()) {
        res.push_back(path);
        return;
    }
    for (int i = index; i < s.size(); ++i) {
        if (isPalindrome(s, index, i)) {
            path.push_back(s.substr(index, i - index + 1));
            partitionHelper(i + 1, s, path, res);
            path.pop_back();
        }
    }
}




int main() {
    string s = "aabb";
    vector<vector<string>> res;
    vector<string> path;
    partitionHelper(0, s, path, res);
    
    cout << "The Palindromic partitions are :-" << endl;
    cout << " [ ";
    for (auto &i : res) {
        cout << "[ ";
        for (auto &j : i) {
            cout << j << " ";
        }
        cout << "] ";
    }
    cout << "]";
    return 0;
}
