// Binary search

#include <bits/stdc++.h>
using namespace std;




// Iterative approach O(log n) and O(1)
int binarySearch(vector<int>& nums, int target) {
    int n = nums.size(); 
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2; // mid = (low + (high - low)) / 2 // for larger search space 
        if (nums[mid] == target) return mid;
        else if (target > nums[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}




// Recursive approach O(log n) and O(log n)
int binarySearch2(vector<int>& nums, int low, int high, int target) {
    if (low > high) return -1; // base case
    int mid = (low + high) / 2;
    if (nums[mid] == target) return mid;
    else if (target > nums[mid])
        return binarySearch2(nums, mid + 1, high, target);
    return binarySearch2(nums, low, mid - 1, target);
}




int main(){
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 17;
    int ind = binarySearch(a, target);
    int ind2=binarySearch2(a,0,7,target);
    if (ind == -1) cout << "The target is not present." << endl;
    else cout << "The target is at index: "
                  << ind << endl;
    if (ind2 == -1) cout << "The target is not present." << endl;
    else cout << "The target is at index: "
                  << ind2 << endl;
    return 0;
}



