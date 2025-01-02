// Largest element in an array

#include<bits/stdc++.h>
using namespace std;




// Brute O(n log n) and O(log n)
int sortArr(vector<int>& arr) {
    sort(arr.begin(),arr.end());
    return arr[arr.size()-1];
}
 



// Optimal O(n) and O(1)
int findLargestElement(int arr[], int n) {
  int max = arr[0];
  for (int i = 1; i < n; i++) {
    if (max < arr[i]) {
      max = arr[i];
    }
  }
  return max;
}




int main() {
    vector<int> arr1 = {2,5,1,3,0};
    int arr2[5] = {8,10,5,7,9};
   
    cout<<"The Largest element in the array is: "<<sortArr(arr1)<<endl;
    cout<<"The Largest element in the array is: "<<findLargestElement(arr2,5);
   
    return 0;
}