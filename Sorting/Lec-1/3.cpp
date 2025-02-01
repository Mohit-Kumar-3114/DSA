// Insertion sort (stable)

#include <bits/stdc++.h>
using namespace std;




// Optimal O(n^2) and O(1)
void insertionSort(int arr[],int n){
 for(int i=1;i<n;i++){
 int j=i;
 while(j>0 and arr[j-1]>arr[j]){
 swap(arr[j-1],arr[j]);
 j--;
 }
 }
}




int main() {
    int arr[5] = {2,5,1,3,0};
    insertionSort(arr,5);
    for(int i=0;i<5;i++){
    cout<<arr[i]<<" ";
    }
    return 0;
}