// Check if the i-th bit is set or not

#include <bits/stdc++.h>
using namespace std;  




// Brute O(log n) and O(log n)
bool checkSetBit(int n,int i){
    string result="";
    while(n>0){
    if(n%2==1) result+="1";
    else result+="0";
    n=n/2;
    }
    reverse(result.begin(),result.end());
     if (i < result.size() && result[result.size() - 1 - i] == '1') { // 000----00001111
        return true; 
    }
    return false; 
}




// Optimal O(1) and O(1)
bool checkSetBit2(int n,int i){
    if((n & (1<<i)) != 0) return true; //  if(((n >> i) & 1) != 0) return true
    return false; 
}




int main(){
    int n=15;
    int i=0;
    bool ans=checkSetBit(n,i);
    if(ans) cout<<"ith bit is set";
    else cout<<"ith bit is not set";
    cout<<endl;
    bool ans2=checkSetBit2(n,i);
    if(ans2) cout<<"ith bit is set";
    else cout<<"ith bit is not set";
    return 0;
}