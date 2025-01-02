// 2 sum problem

#include <bits/stdc++.h>
using namespace std;




// Brute O(n^2) and O(1)
vector<int> twoSum(int n, vector<int> &arr, int target) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                return {i,j};
            }
        }
    }
    return { -1, -1};
}




// Optimal O(n) and O(n)
vector<int> twoSum2(int n, vector<int> &arr, int target) { 
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++){
        int moreNeeded = target - arr[i];
        if (mpp.find(moreNeeded) != mpp.end()) {
            return {mpp[moreNeeded], i};
        }
        mpp[arr[i]] = i;   
    }
    return { -1, -1};
}




int main(){
    int n = 5;
    vector<int> arr = {2, 2, 5, 8, 11};
    int target = 13;
    vector<int> ans = twoSum(n, arr, target);
    cout << "This is the answer for variant 2: [" << ans[0] << ", "
         << ans[1] << "]" << endl;
    vector<int> ans2 = twoSum2(n, arr, target);
    cout << "This is the answer for variant 2: [" << ans2[0] << ", "
         << ans2[1] << "]" << endl;
    return 0;
}
