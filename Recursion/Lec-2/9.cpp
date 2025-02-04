// Subset sum 1

#include <bits/stdc++.h>
using namespace std; 




// Optimal O(2^n) and O(2^n)
void  sub(int arr[], int n,int index, int sum, vector<int>&ans){
    if(index==n){
        ans.push_back(sum);
        return;
    }
   sum+=arr[index];
   sub(arr,n,index+1,sum,ans);
   sum-=arr[index];
   sub(arr,n,index+1,sum,ans);
}




int main(){
    int n=3;
    int arr[]={3,1,2};
    int sum=0;
    vector<int>ans;
    sub(arr,n,0,sum,ans);
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    return 0;
} 