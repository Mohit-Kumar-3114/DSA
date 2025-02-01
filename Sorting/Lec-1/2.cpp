// Bubble sort (stable)

#include <bits/stdc++.h>
using namespace std;




// Optimal O(n^2) and O(1)
void bubbleSort(int arr[],int n){
 for(int i=1;i<n;i++){
 int count=0;
 for(int j=0;j<n-i;j++){
    if(arr[j]>arr[j+1]){
    swap(arr[j],arr[j+1]);
    count++;
    }
  }
  if(count==0) break;
 }
}




int main() {
    int arr[5] = {2,5,1,3,0};
    bubbleSort(arr,5);
    for(int i=0;i<5;i++){
    cout<<arr[i]<<" ";
    }
    return 0;
}