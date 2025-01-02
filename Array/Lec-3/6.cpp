// Count subarrays with given xor k

#include<bits/stdc++.h>
using namespace std;




// Brute O(n^3) and O(1)
int findAllSubarraysWithGivenXor(vector < int > & arr, int k) {
    int n = arr.size(); 
    int cnt = 0;
    for (int i = 0 ; i < n; i++) { 
        for (int j = i; j < n; j++) { 
            int xr = 0;
            for (int K = i; K <= j; K++)
                xr ^= arr[K];
            if (xr == k)
                cnt++;
        }
    }
    return cnt;
}




// Better O(n^2) and O(1)
int findAllSubarraysWithGivenXor2(vector < int > & arr, int k) {
    int n = arr.size(); 
    int cnt = 0;
    for (int i = 0 ; i < n; i++) { 
        int xr = 0;
        for (int j = i; j < n; j++) { 
            xr^= arr[j];
            if (xr == k)
                cnt++;
        }
    }
    return cnt;
}




// Optimal O(n) and O(n)
int findAllSubarraysWithGivenXor3(vector<int>& a, int k) {
    int n = a.size();  
    unordered_map<int, int> preSumMap;
    long long xr = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
         xr^=a[i]; 
        if (xr == k) {
            count++;
        }
        long long rem = xr^k; 
        if (preSumMap.find(rem) != preSumMap.end()) {
            count += preSumMap[rem];
        }
        preSumMap[xr]++;
    }
    return count;
}




int main(){
    vector <int>arr = {3, 1, 2, 4,6,-4,-2};
    int k = 6;
    int cnt = findAllSubarraysWithGivenXor(arr, k);
    cout << "The number of subarrays is: " << cnt << "\n";
    int cnt2 = findAllSubarraysWithGivenXor2(arr, k);
    cout << "The number of subarrays is: " << cnt2 << "\n";
    int cnt3 = findAllSubarraysWithGivenXor3(arr, k);
    cout << "The number of subarrays is: " << cnt3 << "\n";
    return 0;
}
