// Generate all binary strings

#include <bits/stdc++.h>
using namespace std;




// Optimal O(2^n * n) and O(2^n * n)
void generate(vector<string>& ans, string word, int n) {
    if (n == word.length()) {
        ans.push_back(word);
        return;
    }

    if (word.empty() || word.back() == '1') {
        generate(ans, word + "0", n);
        generate(ans, word + "1", n);
    } else {
        generate(ans, word + "1", n);
    }
}




int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    vector<string> ans;
    generate(ans, "", n); 
    cout << "Valid strings of length " << n << " are: \n";
    for (const string& str : ans) {
        cout << str << endl;
    }
    return 0;
}
