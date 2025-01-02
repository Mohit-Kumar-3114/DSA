// Book allocation problem 

#include <bits/stdc++.h>
using namespace std;




bool canAllocate(vector<int> &arr, int pages, int m) {
    int students = 1;
    int pagesStudent = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (pagesStudent + arr[i] <= pages) {
            pagesStudent += arr[i];
        } else {
            students++;
            pagesStudent = arr[i];
            if (students > m) {
                return false;
            }
        }
    }
    return true;
}




// Brute O(n * sum - maxi) and O(1)
int findPages(vector<int>& arr, int n, int m) {
    if (m > n) return -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    for (int pages = low; pages <= high; pages++) {
        if (canAllocate(arr, pages, m)) {
            return pages;
        }
    }
    return low;
}




// Optimal O(n * log(sum - maxi)) and O(1)
int findPages2(vector<int>& arr, int n, int m) {
    if (m > n) return -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int ans = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (canAllocate(arr, mid, m)) {
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
    int ans = findPages(arr, n, m);
    cout << "The answer is: " << ans << "\n";
    int ans2 = findPages2(arr, n, m);
    cout << "The answer is: " << ans2 << "\n";
    return 0;
}
