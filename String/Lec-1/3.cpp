// Largest odd number in a string

#include <bits/stdc++.h>
using namespace std;




// Optimal O(n) and O(n)
string largestOddNumber(string num) {
    string ans="";
    int index=-1;
    for(int i=num.length()-1;i>=0;i--){
    int number=num[i]-'0';
    if(number%2==1){
    index=i;
    break;
    }
    } 
    if(index==-1) return ans;
    else {
    for(int i=0;i<=index;i++) ans+=num[i];
    }  
    return ans;
}




int main() {
    string num = "123456";
    string result = largestOddNumber(num);
    cout << "Largest odd number: " << result << endl;
    return 0;
}
