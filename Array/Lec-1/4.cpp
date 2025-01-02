// Remove duplicates from sorted array

#include<bits/stdc++.h>
using namespace std;




// Optimal O(n) and O(1)
int removeDuplicates(int arr[], int n){  
  int j = 0;
  for (int i = 1; i < n; i++) {
    if (arr[j] != arr[i]) {
      j++;
      arr[j] = arr[i];
    }
  }
  return j + 1;
}




int main() {
  int arr[] = {1,1,2,2,2,3,3};
  int n = sizeof(arr)/sizeof(arr[0]);
  int k = removeDuplicates(arr, n);
  cout << "The array after removing duplicate elements is " << endl;
  for (int i = 0; i < k; i++) {
    cout << arr[i] << " ";
  }
}

