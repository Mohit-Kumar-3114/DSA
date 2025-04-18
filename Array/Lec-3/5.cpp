// Longest subarray with sum 0 

#include <bits/stdc++.h>
using namespace std;




// Brute O(n^3) and O(1)
int getLongestSubarray(vector<int>& a, long long k) {
    int n = a.size(); 
    int len = 0;
    for (int i = 0; i < n; i++) { 
        for (int j = i; j < n; j++) { 
            long long s = 0;
            for (int K = i; K <= j; K++) {
                s += a[K];
            }
            if (s == k)
                len = max(len, j - i + 1);
        }
    }
    return len;
}




// Better O(n^2) and O(1)
int getLongestSubarray2(vector<int>& a, long long k) {
    int n = a.size(); 
    int len = 0;
    for (int i = 0; i < n; i++) { 
        long long s = 0;
        for (int j = i; j < n; j++) { 
            s += a[j];
            if (s == k)
                len = max(len, j - i + 1);
        }
    }
    return len;
}




// Optimal O(n) and O(n)
int getLongestSubarray3(vector<int>& a, long long k) { 
    int n = a.size();  
    unordered_map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i]; 
        if (sum == k) {
            maxLen =  i + 1; 
        }
        long long rem = sum - k; 
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;  
        } 
    }
    return maxLen;
}




int main(){
    vector<int> a = {2, 3, -5, 1, 9};
    long long k = 0;
    int len = getLongestSubarray(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    int len2 = getLongestSubarray2(a, k);
    cout << "The length of the longest subarray is: " << len2 << "\n";
    int len3 = getLongestSubarray3(a, k);
    cout << "The length of the longest subarray is: " << len3 << "\n";
    return 0;
}