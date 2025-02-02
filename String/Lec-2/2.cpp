// Maximum nesting depth of paranthesis

#include <bits/stdc++.h>
using namespace std;




// Optimal O(n) and O(1)
 int maxDepth(string s) {
    int count=0;
    int maxDepth=0;
    for(int i=0;i<s.length();i++){
    if(s[i]=='('){
    count++;
    maxDepth=max(maxDepth,count);
    }
    else if(s[i]==')') count--;
    }
    return maxDepth;
}




int main(){
    string s="(1)+((2))+(((3)))";
    cout<<maxDepth(s);
    return 0;
}