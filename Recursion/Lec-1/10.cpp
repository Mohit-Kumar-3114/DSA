// Kth permutation 

#include <bits/stdc++.h>
using namespace std;




// Optimal O(n^2) and O(n)
string getPermutation(int n, int k) {
    int fact = 1;
    vector<int> numbers;

    for (int i = 1; i <= n; i++) {
        fact *= i;
        numbers.push_back(i);
    }

    string ans = "";
    k--; // Convert to 0-based index

    for (int i = 0; i < n; i++) {
        fact /= numbers.size(); // Reduce factorial at each step
        int index = k / fact;
        ans += to_string(numbers[index]);
        numbers.erase(numbers.begin() + index);
        k %= fact;
    }

    return ans;
}




int main() {
    int n = 4, k = 17;
    cout << "The " << k << "th permutation of " << n << " is: " << getPermutation(n, k) << endl;
    return 0;
}
