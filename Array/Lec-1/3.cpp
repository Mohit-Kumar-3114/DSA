// Check if the array is sorted

#include <bits/stdc++.h>
using namespace std;




// Brute O(n^2) and O(1)
bool isSorted(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[i])
        return false;
    }
  }
  return true;
}




// Optimal O(n) and O(1)
bool isSorted2(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    if (arr[i] < arr[i - 1])
      return false;
  }
  return true;
}




int main() {
  int arr[] = {5, 2, 3, 4, 5}, n = 5;
  bool ans = isSorted(arr, n);
  if (ans) cout << "True" << endl;
  else cout << "False" << endl;
  bool ans2 = isSorted2(arr, n);
  if (ans2) cout << "True" << endl;
  else cout << "False" << endl;
  return 0;
}

