// Find the square root of a number 

#include <bits/stdc++.h>
using namespace std;




// Optimal O(log n) and O(1)
long long int floorSqrt(long long int n) {
    long long int s = 0;
    long long int e = n;
    long long int ans = 0;
        while (s <= e) {
            long long int mid = s + (e - s) / 2;
            long long int temp = mid * mid; 
            if (temp == n) {
                return mid;
            } else if (temp < n) {
                ans = mid; 
                s = mid + 1; 
            } else {
                e = mid - 1; 
            }
        }
        return ans;
}




int main(){
    int n = 39;
    long long int ans = floorSqrt(n);
    cout << "The floor of square root of " << n
         << " is: " << ans << "\n";
    return 0;
}

