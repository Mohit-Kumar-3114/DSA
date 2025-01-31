// Find factorial of a number using recursion

#include <bits/stdc++.h>
using namespace std;  




// Optimal O(n) and O(n)
int factorial(int n){ 
if(n==1) return 1;
return n*factorial(n-1);
}




int main(){
    int n=5;
    cout<<factorial(n);
    return 0;
}