// Multiply two integers 

#include <bits/stdc++.h>
using namespace std;  




// Optimal O(min(a,b)) and O(min(a,b))
int multiply(int a, int b){
    if(a==0 or b==0) return 0;
    return a>b ? a+multiply(a,b-1) : b+multiply(b,a-1);
}




int main(){
    int a=10;
    int b=20;
    cout<<multiply(a,b);
    return 0;
}