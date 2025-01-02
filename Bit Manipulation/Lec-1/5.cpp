// Toggle the ith bit

#include <bits/stdc++.h>
using namespace std;  




// Brute O(log n) and O(log n)
string ToggleBit(int n,int i){
    string result="";
    while(n>0){
    if(n%2==1) result+="1";
    else result+="0";
    n=n/2;
    }
    reverse(result.begin(),result.end());
     if (i < result.size()){
      if(result[result.size() - 1 - i] == '1') { 
       result[result.size() - 1 - i] = '0';
    }
     else result[result.size() - 1 - i] = '1';
     } 
    return result; // convert to decimal if asked
}




// Optimal O(1) and O(1)
int ToggleBit2(int n,int i){
    return (n ^ (1 << i)); 
}




int main(){
    int n=16;
    int i=2;
    string ans=ToggleBit(n,i);
    cout<<ans;
    cout<<endl;
    int ans2=ToggleBit2(n,i);
    cout<<ans2;
    return 0;
}