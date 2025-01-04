// Find xor of numbers from 1 to n

#include <bits/stdc++.h>
using namespace std;  




// Brute O(n) and O(1)
int FindXor(int n){ 
    int ans=0;
    for(int i=1;i<=n;i++) ans=ans^i;
    return ans; 
}




// Optimal O(1) and O(1)
int FindXor2(int n){  
    if(n%4==1) return 1;
    else if(n%4==2) return n+1;
    else if(n%4==3) return 0;
    else return n; 
}




int main(){
    int n=44;
    int ans=FindXor(n);
    int ans2=FindXor2(n);
    cout<<ans<<endl;
    cout<<ans2<<endl;
    return 0;
}