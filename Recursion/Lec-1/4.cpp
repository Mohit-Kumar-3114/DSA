// Find sum of array using recursion

#include <bits/stdc++.h>
using namespace std;  




// Optimal O(n) and O(n)
int print_sum(int arr[],int n){ 
if(n==1) return arr[0];
return arr[n-1]+print_sum(arr,n-1);
}




int main(){
    int arr[]={1,2,3,4,5};
    int n=5;
    cout<<print_sum(arr,n);
    return 0;
}