// First and last occurence of an element

#include<bits/stdc++.h>
using namespace std;




// Optimal O(2 log n) and O(1)
vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> ans(2, -1);
    int s = 0;
    int e = nums.size() - 1;
    // First binary search to find the first occurrence of target
    while (s <= e) {
        int mid = s + ((e - s) / 2);
        if (nums[mid] == target) {
            ans[0] = mid;
            e = mid - 1; // Move left to find the first occurrence
        }
        else if (nums[mid] > target) {
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }
    s = 0;
    e = nums.size() - 1;
    // Second binary search to find the last occurrence of target
    while (s <= e) {
        int mid = s + ((e - s) / 2);
        if (nums[mid] == target) {
            ans[1] = mid;
            s = mid + 1; // Move right to find the last occurrence
        }
        else if (nums[mid] > target) {
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }
    return ans;
}




int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> result = searchRange(nums, target);
    cout << "First and last positions of " << target << " are: "
         << result[0] << " and " << result[1] << endl;
    return 0;
}
