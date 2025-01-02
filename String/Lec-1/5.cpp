// Isomorphic string

#include <bits/stdc++.h>
using namespace std; 




// Optimal O(n) and O(1)
bool isIsomorphic(string& s, string& t) {
    int arr1[256] = {0};
    int arr2[256] = {0};
    for (int i = 0; i < s.length(); i++) {
        if (arr1[s[i]] != arr2[t[i]]) 
            return false;
         // Map the current character positions
        arr1[s[i]] = i + 1;
        arr2[t[i]] = i + 1;
    }
    return true;
}




int main() {
    string s = "bbbaaaba";
    string t = "aaabbaba";
    if (isIsomorphic(s, t)) {
        std::cout << "Strings are isomorphic!" << std::endl;
    } else {
        std::cout << "Strings are not isomorphic!" << std::endl;
    }
    return 0;
}
