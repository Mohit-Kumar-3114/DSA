// Check if array is sorted or not

#include <bits/stdc++.h>
using namespace std;  




// Optimal O(n) and O(n)
bool check(int arr[],int n){ 
if(n==1) return true;
return arr[n-1]>=arr[n-2] && check(arr,n-1);
}




int main(){
    int arr[]={1,2,3,4,5};
    int n=5;
    cout<<check(arr,n);
    return 0;
}