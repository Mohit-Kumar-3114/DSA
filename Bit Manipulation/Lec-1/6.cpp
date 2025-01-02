// Remove the last (rightmost) set bit 

#include <bits/stdc++.h>
using namespace std;  




// Brute O(log n) and O(log n)
string RemoveLastSetBit(int n){
    string result="";
    while(n>0){
    if(n%2==1) result+="1";
    else result+="0";
    n=n/2;
    }
    reverse(result.begin(),result.end());
    for(int i=result.size()-1;i>=0;i--){
        if(result[i]=='1'){
            result[i]='0';
            break;
        }
    }
    return result; // convert to decimal if asked
}




// Optimal O(1) and O(1)
int RemoveLastSetBit2(int n){
    return (n & (n - 1)); 
}




int main(){
    int n=40;
    string ans=RemoveLastSetBit(n);
    cout<<ans;
    cout<<endl;
    int ans2=RemoveLastSetBit2(n);
    cout<<ans2;
    return 0;
}