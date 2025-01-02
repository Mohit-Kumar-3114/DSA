// Count number of bits to be flipped to convert A to B

#include <bits/stdc++.h>
using namespace std;  




// Optimal O(no. of set bits) and O(1)
int CountSetBitRequired(int a, int b){
    int n=a^b;
    int count=0;
    while(n>0){
     n= n & n-1;
     count++;
    }
    return count; 
}




int main(){
    int a=14;
    int b=15;
    int ans=CountSetBitRequired(a,b);
    cout<<ans<<endl;
    return 0;
}