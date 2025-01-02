// Find missing number in an array

#include <bits/stdc++.h>
using namespace std;




// Brute O(n^2) and O(1)
int missingNumber(vector<int>& nums, int n) {
    for (int i = 0; i <= n; i++) {
        bool found = false;
        for (int j = 0; j < n; j++) {
            if (nums[j] == i) {
                found = true;
                break;
            }
        }
        if (!found) {
            return i;
        }
    }
    return -1; 
}




// Optimal O(n) and O(1)
int missingNumber2(vector<int>&a, int N) {
    int sum = (N * (N + 1)) / 2; 
    int s2 = 0;
    for (int i = 0; i < N ; i++) {
        s2 += a[i]; 
    }
    int missingNum = sum-s2;
    return missingNum;
}




// Optimal O(n) and O(1)
int missingNumber3(vector<int>&a, int N) { 
    int xor1 = 0, xor2 = 0;  
    for (int i = 0; i < N ; i++) {  
        xor2 = xor2 ^ a[i];  
        xor1 = xor1 ^ (i + 1); 
    }
    return (xor1 ^ xor2);
}




int main(){
    int N = 4;
    vector<int> a = {1, 0, 3, 4};
    int ans = missingNumber(a, N);
    cout << "The missing number is: " << ans << endl;
    int ans2 = missingNumber2(a, N);
    cout << "The missing number is: " << ans2 << endl;
    int ans3 = missingNumber3(a, N);
    cout << "The missing number is: " << ans3 << endl;
    return 0;
}

