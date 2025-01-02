// Count subarrays with given sum k

#include<bits/stdc++.h>
using namespace std;




// Brute O(n^3) and O(1)
int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    int n = arr.size(); 
    int cnt = 0;
    for (int i = 0 ; i < n; i++) { 
        for (int j = i; j < n; j++) { 
            int sum = 0;
            for (int K = i; K <= j; K++)
                sum += arr[K];
            if (sum == k)
                cnt++;
        }
    }
    return cnt;
}




// Better O(n^2) and O(1)
int findAllSubarraysWithGivenSum2(vector < int > & arr, int k) {
    int n = arr.size(); 
    int cnt = 0;
    for (int i = 0 ; i < n; i++) { 
        int sum = 0;
        for (int j = i; j < n; j++) { 
            sum += arr[j];
            if (sum == k)
                cnt++;
        }
    }
    return cnt;
}




// Optimal O(n) and O(n)
int findAllSubarraysWithGivenSum3(vector<int>& a, int k) {
    int n = a.size();  
    unordered_map<int, int> preSumMap;
    long long sum = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i]; 
        if (sum == k) {
            count++;
        }
        long long rem = sum - k; 
        if (preSumMap.find(rem) != preSumMap.end()) {
            count += preSumMap[rem];
        }
        preSumMap[sum]++;
    }
    return count;
}




int main(){
    vector <int>arr = {3, 1, 2, 4,6,-4,-2};
    int k = 6;
    int cnt = findAllSubarraysWithGivenSum(arr, k);
    cout << "The number of subarrays is: " << cnt << "\n";
    int cnt2 = findAllSubarraysWithGivenSum2(arr, k);
    cout << "The number of subarrays is: " << cnt2 << "\n";
    int cnt3 = findAllSubarraysWithGivenSum3(arr, k);
    cout << "The number of subarrays is: " << cnt3 << "\n";
    return 0;
}
