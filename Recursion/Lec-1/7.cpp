// Convert string to integer

#include <bits/stdc++.h>
using namespace std;  




// Optimal O(n) and O(n)
int str2num(string s,int index,int place){ 
if(index<0) return 0;
int temp=s[index]-'0';
return temp*place + str2num(s,index-1,place*10);
}




int main(){
    string s="518";
    cout<<str2num(s,s.length()-1,1);
    return 0;
}