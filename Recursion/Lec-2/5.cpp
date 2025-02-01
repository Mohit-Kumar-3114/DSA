// Count all subsequences with given sum k

#include <bits/stdc++.h>
using namespace std; 




// Optimal O(2^n) and O(n)
int sub(int arr[], int n,int index, int k, int sum){
    if(index==n){
        if(sum==k){
           return 1;
        }
        return 0;
    }
   sum+=arr[index];
   int l=sub(arr,n,index+1,k,sum);
   sum-=arr[index];
   int r=sub(arr,n,index+1,k,sum);
   return l+r;
}




int main(){
    int n=3;
    int arr[]={3,1,2};
    int count=0;
    int k=3;
    int sum=0;
    cout<<sub(arr,n,0,k,sum);
    return 0;
}