// Painter's partitions

#include <bits/stdc++.h>
using namespace std;




bool canPaint(vector<int> &arr, int maxTime, int k) {
    int painters = 1;
    int timeForPainter = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (timeForPainter + arr[i] <= maxTime) {
            timeForPainter += arr[i];
        } else {
            painters++;
            timeForPainter = arr[i];
            if (painters > k) {
                return false;
            }
        }
    }
    return true;
}




// Brute O(n * sum - maxi) and O(1)
int minTimeToPaint(vector<int>& arr, int n, int k) {
    if (k > n) return -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    for (int maxTime = low; maxTime <= high; maxTime++) {
        if (canPaint(arr, maxTime, k)) {
            return maxTime;
        }
    }
    return low;
}




// Optimal O(n * log(sum - maxi)) and O(1)
int minTimeToPaintOptimal(vector<int>& arr, int n, int k) {
    if (k > n) return -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int ans = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (canPaint(arr, mid, k)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}




int main() {
    vector<int> arr = {10, 20, 30, 40};
    int n = 4;
    int k = 2;  
    int ans = minTimeToPaint(arr, n, k);
    cout << "The minimum time to paint is: " << ans << "\n";
    int ans2 = minTimeToPaintOptimal(arr, n, k);
    cout << "The minimum time to paint is: " << ans2 << "\n";
    return 0;
}
