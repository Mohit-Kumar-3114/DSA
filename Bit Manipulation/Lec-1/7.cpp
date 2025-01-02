// Check if a number is power of 2

#include <bits/stdc++.h>
using namespace std;  




// Brute O(log n) and O(log n)
bool CheckPower(int n){
    string result="";
    while(n>0){
    if(n%2==1) result+="1";
    else result+="0";
    n=n/2;
    }
    reverse(result.begin(),result.end());
    int count=0;
    for(int i=result.size()-1;i>=0;i--){
        if(result[i]=='1'){
            count++;
        }
    }
    if (count==1) return true;
    else return false; 
}




// Optimal O(1) and O(1)
bool CheckPower2(int n){
   if((n & (n - 1)) == 0 ) return true;
   else return false; 
}




int main(){
    int n=40;
    bool ans=CheckPower(n);
    if (ans) cout<<"yes n is power of 2";
    else cout<<"n is not power of 2";
    cout<<endl;
    bool ans2=CheckPower2(n);
    if (ans2) cout<<"yes n is power of 2";
    else cout<<"n is not power of 2";
    return 0;
}