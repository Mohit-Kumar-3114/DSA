// Decimal to binary and Binary to decimal

#include <bits/stdc++.h>
using namespace std;  




// Optimal O(log n) and O(log n)
string decimalToBinary(int n){
    string result="";
    while(n>0){
    if(n%2==1) result+="1";
    else result+="0";
    n=n/2;
    }
    reverse(result.begin(),result.end());
    return result;
}




// Optimal O(n) and O(1)
int binaryToDecimal(string s){
    int ans=0;
    int power=1;
    for(int i=s.length()-1;i>=0;i--){
    if(s[i]=='1'){
        ans=ans+power;
    }
    power=power*2;
    }
    return ans;
}




int main(){
    int n=15;
    string ans=decimalToBinary(n);
    cout<<ans<<endl;
    string s="1111";
    int num=binaryToDecimal(s);
    cout<<num;
    return 0;
}