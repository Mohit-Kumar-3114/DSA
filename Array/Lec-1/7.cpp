// Move zeroes to end

#include <bits/stdc++.h>
using namespace std;




// Brute O(2n) and O(n) 
vector<int> moveZeros(int n, vector<int> a) {
    vector<int> temp;
    for (int i = 0; i < n; i++) {
        if (a[i] != 0)
            temp.push_back(a[i]);
    }
    int nz = temp.size();
    for (int i = 0; i < nz; i++) {
        a[i] = temp[i];
    }
    for (int i = nz; i < n; i++) {
        a[i] = 0;
    }
    return a;
}




// Optimal O(n) and O(1)
vector<int> moveZeros2(int n, vector<int> nums) {
    int j=0;
    for(int i=0;i<n;i++){
    if(nums[i]!=0){
    swap(nums[j],nums[i]);
    j++;
    }}
    return nums;
}




int main(){
    vector<int> arr = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
    int n = 10;
    vector<int> ans = moveZeros(n, arr);
    vector<int> ans2 = moveZeros2(n, arr);
    for (auto &it : ans) {
        cout << it << " ";
    }
    cout << '\n';
    for (auto &it : ans2) {
        cout << it << " ";
    }
    return 0;
}


