// Find minimum in rotated sorted array

#include <bits/stdc++.h>
using namespace std;




// Optimal O(log n) and O(1)
int findMin(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    while (low <= high) {
        int mid = (low + high) / 2;

        //Edge case: only for duplicates
        if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
            ans=min(ans,arr[low]);
            low = low + 1;
            high = high - 1;
            continue;
        }

        // If left side is sorted:
        else if (arr[low] <= arr[mid]) {
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        // If right side is sorted:
        else {
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }
    return ans;
}




int main(){
    vector<int> arr = { 2,2,2,2, 1, 2, 2};
    int ans = findMin(arr);
    cout << "The minimum element is: " << ans << "\n";
    return 0;
}
