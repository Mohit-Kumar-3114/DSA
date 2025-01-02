// Split array largest sum

#include <bits/stdc++.h>
using namespace std;




bool canSplit(vector<int> &arr, int maxSum, int m) {
    int students = 1;
    int sumForStudent = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (sumForStudent + arr[i] <= maxSum) {
            sumForStudent += arr[i];
        } else {
            students++;
            sumForStudent = arr[i];
            if (students > m) {
                return false;
            }
        }
    }
    return true;
}




// Brute O(n * sum - maxi) and O(1)
int splitArray(vector<int>& arr, int n, int m) {
    if (m > n) return -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    for (int maxSum = low; maxSum <= high; maxSum++) {
        if (canSplit(arr, maxSum, m)) {
            return maxSum;
        }
    }
    return low;
}




// Optimal O(n * log(sum - maxi)) and O(1)
int splitArrayOptimal(vector<int>& arr, int n, int m) {
    if (m > n) return -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int ans = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (canSplit(arr, mid, m)) {
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
    int m = 2;
    int ans = splitArray(arr, n, m);
    cout << "The answer is: " << ans << "\n";
    int ans2 = splitArrayOptimal(arr, n, m);
    cout << "The answer is: " << ans2 << "\n";
    return 0;
}
