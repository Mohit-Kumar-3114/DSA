// Count the number of set bits

#include <bits/stdc++.h>
using namespace std;  




// Optimal O(log n) and O(1)
int CountSetBit(int n){
    int count=0;
    while(n>0){
    if(n%2==1) count++;
    n=n/2;
    }
    return count; 
}




// Optimal O(log n) and O(1)
int CountSetBit2(int n){
    int count=0;
    while(n>0){
    if(n&1) count++; 
    n=n>>1;
    }
    return count; 
}




// Optimal O(no. of set bits) and O(1)
int CountSetBit3(int n){
    int count=0;
    while(n>0){
     n= n & n-1;
     count++;
    }
    return count; 
}




int main(){
    int n=16;
    int ans=CountSetBit(n);
    int ans2=CountSetBit2(n);
    int ans3=CountSetBit3(n);
    cout<<ans<<endl;
    cout<<ans2<<endl;
    cout<<ans3<<endl;
    return 0;
}