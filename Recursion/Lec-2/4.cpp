// Print all subsequences with given sum k

#include <bits/stdc++.h>
using namespace std; 




// Optimal O(2^n * n) and O(2n)
void print(vector<int>&list){
cout<<"[";
for(int i=0;i<list.size();i++){
cout<<list[i]<<" ";
}
cout<<"]";
cout<<endl;
}

void sub(int arr[], int n,int index, vector<int>&list, int k, int sum){
    if(index==n){
        if(sum==k){
            print(list);
        }
        return;
    }
   list.push_back(arr[index]);
   sum+=arr[index];
   sub(arr,n,index+1,list,k,sum);
   list.pop_back();
   sum-=arr[index];
   sub(arr,n,index+1,list,k,sum);
}




int main(){
    int n=3;
    int arr[]={3,1,2};
    vector<int>list;
    int k=3;
    int sum=0;
    sub(arr,n,0,list,k,sum);
    return 0;
}