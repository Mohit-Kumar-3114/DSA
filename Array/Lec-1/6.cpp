// Left rotate an array by d place 

#include <iostream>
using namespace std;




// Optimal O(2n) and O(1)
void Reverse(int arr[], int start, int end){
  while (start <= end){
    swap(arr[start],arr[end]);
    start++;
    end--;
  }
}

void Rotateeletoleft(int arr[], int n, int k){
  k=k%n;
  Reverse(arr, 0, n - 1);
  Reverse(arr, 0, n - k - 1);
  Reverse(arr, n - k, n - 1);
}




int main(){
  int arr[] = {1, 2, 3, 4, 5, 6, 7};
  int n = 7;
  int k = 2;
  Rotateeletoleft(arr, n, k);
  cout << "After Rotating the k elements to left ";
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
    cout << endl;
  return 0;
}