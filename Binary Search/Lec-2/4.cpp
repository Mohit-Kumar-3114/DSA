// Minimum number of days to make m bouquets

#include <bits/stdc++.h>
using namespace std;




bool possible(vector<int> &arr, int day, int m, int k) {
    int n = arr.size(); 
    int cnt = 0;
    int noOfB = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] <= day) {
            cnt++;
        }
        else {
            noOfB += (cnt / k);
            cnt = 0;
        }
    }
    noOfB += (cnt / k);
    return noOfB >= m;
}




// Brute O(maxi - mini * n) and O(1)
int roseGarden(vector<int> arr, int k, int m) {
    int value=m*k;
    int n = arr.size(); 
    if (value > n) return -1; 
    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }

    for (int i = mini; i <= maxi; i++) {
        if (possible(arr, i, m, k))
            return i;
    }
    return -1;
}




// Optimal O(log (maxi - mini) * n) and O(1)
int roseGarden2(vector<int> arr, int k, int m) {
    int val=m*k;
    int n = arr.size(); 
    if (val > n) return -1; 
    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }

    int low = mini, high = maxi;
    int ans=-1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (possible(arr, mid, m, k)) {
            ans=mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
}




int main(){
    vector<int> arr = {7, 7, 7, 7, 13, 11, 11, 7};
    int k = 3;
    int m = 2;
    int ans = roseGarden(arr, k, m);
    if (ans == -1)
        cout << "We cannot make m bouquets.\n";
    else
        cout << "We can make bouquets on day " << ans << "\n";
    int ans2 = roseGarden2(arr, k, m);
    if (ans2 == -1)
        cout << "We cannot make m bouquets.\n";
    else
        cout << "We can make bouquets on day " << ans2 << "\n";
    return 0;
}

