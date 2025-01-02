// Aggressive cows

#include <bits/stdc++.h>
using namespace std;




bool canWePlace(vector<int> &stalls, int dist, int cows) {
    int n = stalls.size(); 
    int cntCows = 1; 
    int last = stalls[0]; 
    for (int i = 1; i < n; i++) {
        if (stalls[i] - last >= dist) {
            cntCows++; 
            last = stalls[i]; 
        }
        if (cntCows >= cows) return true;
    }
    return false;
}




// Brute O(n log n + n * maxi - mini) and O(log n)
int aggressiveCows(vector<int> &stalls, int k) {
    int n = stalls.size(); 
    sort(stalls.begin(), stalls.end());
    int limit = stalls[n - 1] - stalls[0];
    for (int i = 1; i <= limit; i++) {
        if (canWePlace(stalls, i, k) == false) {
            return (i - 1);
        }
    }
    return limit;
}




// Optimal O(n log n + n * log(maxi - mini)) and O(log n)
int aggressiveCows2(vector<int> &stalls, int k) {
    int n = stalls.size(); 
    sort(stalls.begin(), stalls.end());
    int low = 1, high = stalls[n - 1] - stalls[0];
    int ans=0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (canWePlace(stalls, mid, k) == true) {
            ans=mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return ans;
}




int main(){
    vector<int> stalls = {4,2,1,3,6};
    int k = 2;
    int ans = aggressiveCows(stalls, k);
    cout << "The maximum possible minimum distance is: " << ans << "\n";
    int ans2 = aggressiveCows2(stalls, k);
    cout << "The maximum possible minimum distance is: " << ans2 << "\n";
    return 0;
}

