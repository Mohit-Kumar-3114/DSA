// Write a program to find element of a fibonacci series

#include <bits/stdc++.h>
using namespace std;  




// Optimal O(2^n) and O(n)
int fib(int n){ // 0 1 1 2 3 5 8 13 21
if(n==1) return 1;
if(n==0) return 0;
return fib(n-1)+fib(n-2);
}




int main(){
    int n=5;
    cout<<fib(n);
    return 0;
}