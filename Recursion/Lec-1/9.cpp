// Permutations

#include <bits/stdc++.h>
using namespace std;




// Optimal (n * n!) and O(n * n!)
void permute(int index, vector<int> &nums, vector<vector<int>> &ans) {
    if (index == nums.size()) {
            ans.push_back(nums);
        return;
    }

    for (int i = index; i < nums.size(); i++) {
        // if(i!=index and nums[i]==nums[index]) continue; // first sort the array if duplicatee
        swap(nums[index], nums[i]);
        permute(index + 1, nums, ans);
        swap(nums[index], nums[i]);
    }
}




int main() {
    vector<int> nums = {1, 3, 2};
    vector<vector<int>> ans;
    permute(0, nums, ans);

    cout << "Unique Permutations:" << endl;
    for (const auto &perm : ans) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
