// Find the nth root of a number 

#include <bits/stdc++.h>
using namespace std;




// Optimal O(n log m) and O(1)
int NthRoot(int n, int m) {
    long long int s = 0;
    long long int e = m;
        while (s <= e) {
            long long int mid = s + (e - s) / 2;
            long long int temp = 1;
            for (int i = 0; i < n; i++) {
                temp *= mid;
                if (temp > m) break; 
            }
            if (temp == m) {
                return mid; 
            } else if (temp < m) {
                s = mid + 1; 
            } else {
                e = mid - 1; 
            }
        }
        return -1; 
}




int main() {
    int n = 3; 
    int m = 28; 
    int ans = NthRoot(n, m);
    cout << "The " << n << "th root of " << m << " is: " << ans << "\n";
    return 0;
}
