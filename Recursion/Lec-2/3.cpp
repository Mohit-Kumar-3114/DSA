// Print all subsequences 

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

void sub(int arr[], int n,int index, vector<int>&list){
    if(index==n){
        print(list);
        return;
    }
   list.push_back(arr[index]);
   sub(arr,n,index+1,list);
   list.pop_back();
   sub(arr,n,index+1,list);
}




int main(){
    int n=3;
    int arr[]={3,1,2};
    vector<int>list;
    sub(arr,n,0,list);
    return 0;
}