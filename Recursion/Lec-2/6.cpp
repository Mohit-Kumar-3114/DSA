// Check if there exists a subsequence with sum k

#include <bits/stdc++.h>
using namespace std; 




// Optimal O(2^n) and O(n)
bool sub(int arr[], int n,int index, int k, int sum){
    if(index==n){
        if(sum==k){
           return true;
        }
        return false;
    }
   sum+=arr[index];
   if(sub(arr,n,index+1,k,sum)) return true;
   sum-=arr[index];
   if(sub(arr,n,index+1,k,sum)) return true;
   return false;
}




int main(){
    int n=3;
    int arr[]={3,1,2};
    int count=0;
    int k=8;
    int sum=0;
    cout<<sub(arr,n,0,k,sum);
    return 0;
}