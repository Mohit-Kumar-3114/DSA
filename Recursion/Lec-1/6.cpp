// Print number to string

#include <bits/stdc++.h>
using namespace std;  




// Optimal O(n) and O(n)
void num2str(string s,int index){ 
string arr[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
if(index==s.length()) return;
cout<<arr[s[index]-'0']<<" ";
num2str(s,index+1);
}




int main(){
    int n=518;
    num2str(to_string(n),0);
    return 0;
}