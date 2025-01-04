// Find xor of numbers from l to r

#include <bits/stdc++.h>
using namespace std;  




// Brute O(n) and O(1)
int FindXor(int l,int r){ 
    int ans=0;
    for(int i=l;i<=r;i++) ans=ans^i;
    return ans; 
}




// Optimal O(1) and O(1)
int helper(int n){
    if(n%4==1) return 1;
    else if(n%4==2) return n+1;
    else if(n%4==3) return 0;
    else return n;
}

int FindXor2(int l, int r){
 int temp1=helper(l-1);
 int temp2=helper(r);
 return temp1^temp2;
}




int main(){
    int l=11;
    int r=16;
    int ans=FindXor(l,r);
    int ans2=FindXor2(l,r);
    cout<<ans<<endl;
    cout<<ans2<<endl;
    return 0;
}