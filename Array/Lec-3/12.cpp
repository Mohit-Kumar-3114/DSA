// Maximum product subarray

#include<bits/stdc++.h>
using namespace std;




// Brute O(n^3) and O(1)
int maxProductSubArray(vector<int>& nums) {
    int result = INT_MIN;
    for(int i=0;i<nums.size();i++) {
        for(int j=i;j<nums.size();j++) {
            int prod = 1;
            for(int k=i;k<=j;k++){ 
                prod *= nums[k];
            }
            result = max(result,prod);    
        }
    }
    return result;
}




// Better O(n^2) and O(1)
int maxProductSubArray2(vector<int>& nums) {
    int result = nums[0];
    for(int i=0;i<nums.size()-1;i++) {
        int p = 1;
        for(int j=i;j<nums.size();j++) {
           p *= nums[j];
           result = max(result,p);
        }
        result = max(result,p); 
    }
    return result;
}




// Optimal O(n) and O(1)
int maxProductSubArray3(vector<int> &arr) {
    int n = arr.size(); 
    int pre = 1, suff = 1;
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (pre == 0) pre = 1;
        if (suff == 0) suff = 1;
        pre *= arr[i];
        suff *= arr[n - i - 1];
        ans = max(ans, max(pre, suff));
    }
    return ans;
}




int main() {
    vector<int> nums = {1,2,-3,0,-4,-5};
    cout<<"The maximum product subarray: "<<maxProductSubArray(nums)<<endl;
    cout<<"The maximum product subarray: "<<maxProductSubArray2(nums)<<endl;
    cout<<"The maximum product subarray: "<<maxProductSubArray3(nums)<<endl;
    return 0;
}