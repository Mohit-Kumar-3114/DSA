// Count goog numbers

#include <bits/stdc++.h>
using namespace std;




// Optimal O(log n) and O(1)
const long long mod = 1e9 + 7;
long long power(long long x, long long n) {
    long long ans = 1;
    x = x % mod; 
    while (n > 0) {
        if (n % 2 == 1) {
            ans = (ans * x) % mod;
            n = n - 1;
        } else {
            x = (x * x) % mod;
            n = n / 2;
        }
    }
    return ans;
}

int countGoodNumbers(long long n) {
    long long odd = n / 2;
    long long even = n - odd;
    long long evenPower = power(5, even);
    long long oddPower = power(4, odd);
    return (evenPower * oddPower) % mod; 
}




int main(){
    long long n;
    cout<<"Enter value of n : ";
    cin >> n;
    cout << countGoodNumbers(n) << endl;
    return 0;
}