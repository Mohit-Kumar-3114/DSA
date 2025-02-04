// Subset 2

#include <bits/stdc++.h>
using namespace std;




// Optimal O(2^n * k) and O(k * x) where k=average length and x=no. of unique subsets
void printAns(vector<vector<int>> &ans) {
    cout << "The unique subsets are " << endl;
    cout << "[ ";
    for (int i = 0; i < ans.size(); i++) {
        cout << "[ ";
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << "]";
    }
    cout << " ]";
}

void findSubsets(int ind, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans) {
    ans.push_back(ds);
    for (int i = ind; i < nums.size(); i++) {
        if (i != ind && nums[i] == nums[i - 1]) continue;
        ds.push_back(nums[i]);
        findSubsets(i + 1, nums, ds, ans);
        ds.pop_back();
    }
}




int main() {
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> ans;
    vector<int> ds;
    sort(nums.begin(), nums.end());
    findSubsets(0, nums, ds, ans);
    printAns(ans);
    return 0;
}
