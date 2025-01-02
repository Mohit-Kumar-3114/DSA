// Second largest element in an array 

#include<bits/stdc++.h>
using namespace std;




// Brute O(n log n) and O(log n) 
void getElements(int arr[],int n){
    if(n==0 || n==1)
    cout<<-1<<" "<<-1<<endl;  
    sort(arr,arr+n);
    int large=arr[n-2]; // without duplicates
    cout<<"Second largest is "<<large<<endl;
}




// Better O(2n) and O(1)
void getElements2(int arr[],int n){
    int large=INT_MIN,second_large=INT_MIN;
    for(int i=0;i<n;i++){
        large=max(large,arr[i]);
    }
    for(int i=0;i<n;i++){
        if(arr[i]>second_large && arr[i]!=large)
            second_large=arr[i];
    };
    cout<<"Second largest is "<<second_large<<endl;
}




// Optimal O(n) and O(1)
int getElements3(int arr[],int n){
    int large=INT_MIN,second_large=INT_MIN;
    int i;
    for (i = 0; i < n; i++){
        if (arr[i] > large){
            second_large = large;
            large = arr[i];
        }
        else if (arr[i] > second_large && arr[i] != large) {
            second_large = arr[i];
        }
    }
    return second_large;                
}




int main(){
    int arr[]={1,2,4,6,7,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    getElements(arr,n);
    getElements2(arr,n);
    cout<<getElements3(arr,n);
    return 0;
}