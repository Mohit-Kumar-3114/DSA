// Left rotate an array by one place 

#include<bits/stdc++.h>
using namespace std;




// Brute O(2n) and O(n)
void solve(int arr[], int n) {
  int temp[n];
  for (int i = 1; i < n; i++) {
    temp[i - 1] = arr[i];
  }
  temp[n - 1] = arr[0];
  for (int i = 0; i < n; i++) {
    cout << temp[i] << " ";
  }
  cout << endl;
}




// Optimal O(2n) and O(1)
void solve2(int arr[], int n) {
  int temp = arr[0]; // storing the first element of array in a variable
  for (int i = 1; i < n ; i++) {
    arr[i-1] = arr[i];
  }
  arr[n - 1] = temp; // assigned the value of variable at the last index
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}




int main() {
  int n=5;
  int arr[]= {1,2,3,4,5};
  int arr2[]= {1,2,3,4,5};
  solve(arr, n);
  solve2(arr2, n);
}

