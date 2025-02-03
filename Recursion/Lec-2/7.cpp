// Combination sum

#include <bits/stdc++.h>
using namespace std;




// Optimal O(2^t * k) and O(k * x) where t=target, k=average length and x=no. of combinations
void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds) {
      if (ind == arr.size()) {
        if (target == 0) {
          ans.push_back(ds);
        }
        return;
      }
      // pick up the element 
      if (arr[ind] <= target) {
        ds.push_back(arr[ind]);
        findCombination(ind, target - arr[ind], arr, ans, ds);
        ds.pop_back();
      }

      findCombination(ind + 1, target, arr, ans, ds);

}




int main(){
  vector < int > v {2,3,6,7};
  int target = 7;
  vector < vector < int >> ans;
  vector<int>ds;
  findCombination(0,target,v,ans,ds);
  cout << "Combinations are: " << endl;
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++)
      cout << ans[i][j] << " ";
    cout << endl;
  }
    return 0;
}