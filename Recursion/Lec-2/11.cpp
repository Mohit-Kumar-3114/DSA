// Combination sum 3

#include<bits/stdc++.h>
using namespace std;




// Optimal O(2^9 * k) and O(k * x) where k=length and x=no. of combinations
void findCombination(int ind,int k,int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds) {
  if (target == 0 and ds.size()==k ) {
    ans.push_back(ds);
    return;
  }
if (ds.size() >= k) return;
  for (int i = ind; i < arr.size(); i++) {
    if (arr[i] > target) break;
    ds.push_back(arr[i]);
    findCombination(i + 1,k, target - arr[i], arr, ans, ds);
    ds.pop_back();
  }
}




int main() {
  vector<int> candidates{1,2,3,4,5,6,7,8,9};
  vector < vector < int >> comb;
  vector < int > ds;
  int target=8;
  int k=3;
  findCombination(0,k, target, candidates, comb, ds);
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