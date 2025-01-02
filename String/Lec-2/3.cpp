// Roman number to integer 

#include <bits/stdc++.h>
using namespace std;




// Optimal O(n) and O(1)
int romanToInt(string s) {
    unordered_map<char, int> roi;
    roi['I'] = 1;
    roi['V'] = 5;
    roi['X'] = 10;
    roi['L'] = 50;
    roi['C'] = 100;
    roi['D'] = 500;
    roi['M'] = 1000;

    int ans = 0;
    for (int i = 0; i < s.length() - 1; i++) {
        if (roi[s[i]] >= roi[s[i + 1]])
            ans += roi[s[i]];
        else
            ans -= roi[s[i]];
    }
    ans += roi[s[s.length() - 1]];
    return ans;
}




int main() {
    string roman = "MCMXCIV";  
    cout << "Integer value of " << roman << " is " << romanToInt(roman) << endl;
    return 0;
}
