// Combination sum 2

#include<bits/stdc++.h>
using namespace std;




// Optimal O(2^n * k) and O(k * x) where k=average length and x=no. of combinations
void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds) {
  if (target == 0) {
    ans.push_back(ds);
    return;
  }
  for (int i = ind; i < arr.size(); i++) {
    if (i > ind && arr[i] == arr[i - 1]) continue;
    if (arr[i] > target) break;
    ds.push_back(arr[i]);
    findCombination(i + 1, target - arr[i], arr, ans, ds);
    ds.pop_back();
  }
}




int main() {
  vector<int> candidates{10,1,2,7,6,1,5};
  sort(candidates.begin(), candidates.end());
  vector < vector < int >> comb;
  vector < int > ds;
  int target=8;
  findCombination(0, target, candidates, comb, ds);
  cout << "[ ";
  for (int i = 0; i < comb.size(); i++) {
    cout << "[ ";
    for (int j = 0; j < comb[i].size(); j++) {
      cout << comb[i][j] << " ";
    }
    cout << "]";
  }
  cout << " ]";
}