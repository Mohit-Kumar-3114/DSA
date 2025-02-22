// Check palindrome number

#include<bits/stdc++.h>
using namespace std;




// Optimal O(log n) and O(1)
int fn(int a){
    int count=0;
    while(a>0){
        int x=a%10;
        count=count*10+x;
        a=a/10;
    }
    return count;
}




int main() {
    int a=676676;
    cout<<(a==fn(a));  
    return 0;
}