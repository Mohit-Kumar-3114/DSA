// Find the intersection of two sorted arrays

#include <bits/stdc++.h>
using namespace std;




// Optimal O(n + m) and O(min(n,m))
vector < int > FindIntersection(int arr1[], int arr2[], int n, int m) {
    int i=0,j=0;  
    vector<int>ans;
    while(i<n and j<m){ 
        if(arr1[i]<arr2[j]) i++;
        else if(arr1[i]>arr2[j]) j++;
        else{
        // if(ans.empty() || ans.back()!=arr1[i]){ // for avoiding duplicates
        // ans.push_back(arr1[i]);
        // }
        ans.push_back(arr1[i]);
        i++;
        j++;
        }
    }
    return ans;
}




int main(){
  int n = 10, m = 7;
  int arr1[] = {1, 2, 3, 4, 4, 6, 7, 8, 9, 10};
  int arr2[] = {2, 3, 4, 4,6, 7, 8, 9};
  vector < int > ans = FindIntersection(arr1, arr2, n, m);
  cout << "Intersection of arr1 and arr2 is  " << endl;
  for (auto & val: ans)
    cout << val << " ";
  return 0;
}



