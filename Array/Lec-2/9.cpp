// Leaders in an array

#include<bits/stdc++.h>
using namespace std;




// Brute O(n^2) and O(n)
vector<int> printLeadersBruteForce(int arr[], int n) { 
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    bool leader = true;
    for (int j = i + 1; j < n; j++)
      if (arr[i] < arr[j]) {
        leader = false;
        break;
      }
    if (leader)
    ans.push_back(arr[i]);  
  }
  return ans;
}




// Optimal O(n) and O(n)
vector<int> leadersOptimal(int n, int arr[]) {
    vector<int>ans;
    ans.push_back(arr[n-1]);
    int maxi=arr[n-1];
    for(int i=n-2;i>=0;i--){
    if(arr[i]>=maxi) {
        maxi=arr[i];
        ans.push_back(arr[i]);
    }}
    reverse(ans.begin(),ans.end());
    return ans;
}




int main() {
  int n = 6;
  int arr[n] = {10, 22, 12, 3, 0, 6}; 
  vector<int> ans = printLeadersBruteForce(arr,n);
  vector<int> ans2= leadersOptimal(n,arr);
  for(int i = 0;i<ans.size();i++){
      cout<<ans[i]<<" ";
  }
  cout<<endl;
  for(int i = 0;i<ans2.size();i++){
      cout<<ans2[i]<<" ";
  }
  cout<<endl;
  return 0;
}


